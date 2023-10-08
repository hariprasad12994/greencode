#include <stdio.h>
#include <stdbool.h>


void print_matrix(int arr[][4], int row, int col) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      printf("%d  ", arr[i][j]);
    }
    printf("\n");
  }
}


bool is_matrix_filled(int arr[][4], int row, int col) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(arr[row][col] == 0)
        return false;
    }
  }
  return true;
}


bool is_block_already_present_in_row(int arr[][4], int row, int col, int row_id, int block_height) {
  int count = 0;
  for(int idx = 0; idx < col; idx++) {
    // printf("row check = %d\n", count);
    if(arr[row_id][idx] == block_height) {
      count++;
      if(count > 1)
        return true;
    }
  }
  return false;
}


bool is_block_already_present_in_column(int arr[][4], int row, int col, int col_id, int block_height) {
  int count = 0;
  for(int idx = 0; idx < row; idx++) {
    // printf("column check = %d\n", count);
    if(arr[idx][col_id] == block_height) {
      count++;
      if(count > 1)
        return true;
    }
  }
  return false;
}


bool is_visibility_satifisfied_left_right(int arr[][4], int row, int col, int row_id, int clues[][4]) {
  for(int i = 0; i < row; i++) {
    int max = arr[i][0];
    int seen = 1;
    for(int j = 1; j < col; j++) {
      if(arr[i][j] > max) {
        max = arr[i][j];
        seen++;
      }
    }
    printf("L-R current = %d, constraint = %d\n", seen, clues[0][i]);
    if(clues[0][i] < seen)
      return false;
  }
  return true;
}


bool is_visibility_satifisfied_right_left(int arr[][4], int row, int col, int row_id, int clues[][4]) {
  for(int i = 0; i < row; i++) {
    int max = arr[i][col - 1];
    int seen = 1;
    for(int j = col - 2; j >= 0; j--) {
      if(arr[i][j] > max) {
        max = arr[i][j];
        seen++;
      }
    }
    printf("R-L current = %d, constraint = %d\n", seen, clues[1][i]);
    if(clues[1][i] < seen)
      return false;
  }
  return true;
}


bool is_visibility_satifisfied_up_down(int arr[][4], int row, int col, int row_id, int clues[][4]) {
  for(int i = 0; i < col; i++) {
    int max = arr[0][i];
    int seen = 1;
    for(int j = 0; j < row; j++) {
      if(arr[j][i] > max) {
        max = arr[j][i];
        seen++;
      }
    }
    printf("U-D current = %d, constraint = %d\n", seen, clues[2][i]);
    if(clues[2][i] < seen)
      return false;
  }
  return true;
}


bool is_visibility_satifisfied_down_up(int arr[][4], int row, int col, int row_id, int clues[][4]) {
  for(int i = 0; i < col; i++) {
    int max = arr[row - 1][i];
    int seen = 1;
    for(int j = row - 2; j >= 0; j--) {
      if(arr[j][i] > max) {
        max = arr[j][i];
        seen++;
      }
    }
    printf("D-U current = %d, constraint = %d\n", seen, clues[3][i]);
    if(clues[3][i] < seen)
      return false;
  }
  return true;
}


bool is_grid_valid(int arr[][4], int row, int col, int curr_row, int curr_col, int clues[][4], int block_height) {
  // is_visibility_satifisfied_left_right(arr, row, col, curr_row, clues);
  // is_visibility_satifisfied_right_left(arr, row, col, curr_row, clues);
  // is_visibility_satifisfied_up_down(arr, row, col, curr_row, clues);
  // is_visibility_satifisfied_down_up(arr, row, col, curr_row, clues);
  //
  // return (!is_block_already_present_in_row(arr, row, col, curr_row, block_height) &&
  //         !is_block_already_present_in_column(arr, row, col, curr_col, block_height));
  //
  return (!is_block_already_present_in_row(arr, row, col, curr_row, block_height) &&
          !is_block_already_present_in_column(arr, row, col, curr_col, block_height) && 
          is_visibility_satifisfied_left_right(arr, row, col, curr_row, clues) &&
          is_visibility_satifisfied_right_left(arr, row, col, curr_row, clues) &&
          is_visibility_satifisfied_up_down(arr, row, col, curr_row, clues) &&
          is_visibility_satifisfied_down_up(arr, row, col, curr_row, clues));
}


int solve(int arr[][4], int row, int col, int curr_row, int curr_col, int clues[][4]) {
  // printf("[a][%d][%d]\n", curr_row, curr_col);
  // print_matrix(arr, row, col);
  // printf("\n");

  // We have completed scanning and assigning blocks for all the rows and columns
  if(curr_col == col - 1 && curr_row == row - 1)
    return 1;

  // todo rename to guess
  int current_block_height = 1;
  for(; current_block_height <= 4; current_block_height++) { 
    arr[curr_row][curr_col] = current_block_height;

    printf("[b][%d][%d]\n", curr_row, curr_col);
    print_matrix(arr, row, col);
    printf("\n");

    if(is_grid_valid(arr, row, col, curr_row, curr_col, clues, current_block_height)) {
      if(curr_col < col -1)
        return solve(arr, row, col, curr_row, curr_col + 1, clues);
      else if(curr_row < row - 1)
        return solve(arr, row, col, curr_row + 1, 0, clues);
    }
    // The value we placed failed to satisfy the constrant so reset the value and recurse
    else {
      arr[curr_row][curr_col] = 0;
      // return 0;
    }
  }
  return 0;
}


void recursive_print(int a[][4], int row, int col, int curr_row, int curr_col) {
  printf("[%d][%d] %d\n", curr_row, curr_col, a[curr_row][curr_col]);
  if(curr_row == row - 1 && curr_col == col - 1)
    return;
  if(curr_col < col - 1)
    recursive_print(a, row, col, curr_row, curr_col + 1);
  else if(curr_row < row - 1)
    recursive_print(a, row, col, curr_row + 1, 0);
}


int main(void) {
  int arr[4][4] = {
    {1, 2, 3, 4},
    {4, 3, 2, 1},
    {1, 2, 3, 4},
    {4, 3, 2, 1}
  };

  int empty_arr[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  };


  int clues[4][4] = {
    {4, 3, 2, 1},
    {1, 2, 2, 2},
    {4, 3, 2, 1},
    {1, 2, 2, 2}
  };
  
  int matrix[4][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 9},
    {-1, -2, -3, -4},
    {-5, -6, -7, -8}
  };


  // recursive_print(matrix, 4, 4, 0, 0);

  // print_matrix(arr, 4, 4);
  solve(empty_arr, 4, 4, 0, 0, clues);
  printf("\n");
  // print_matrix(arr, 4, 4);

  return 0;
}
