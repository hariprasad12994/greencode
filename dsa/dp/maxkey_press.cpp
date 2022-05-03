#include <iostream>


int max_key_press(int allowed_num_of_keypress, int count_of_a) {
  if(allowed_num_of_keypress <= 0) return count_of_a;

  auto var_2 = max_key_press(allowed_num_of_keypress - 1, count_of_a + 1);

  auto var_1 = 0;
  if(allowed_num_of_keypress >= 3)
      var_1 = max_key_press(allowed_num_of_keypress - 3, count_of_a * 2);

  return std::max(var_1, var_2);
}

int main(void){
  std::cout << max_key_press(6, 0) << '\n';
  std::cout << max_key_press(7, 0) << '\n';
  std::cout << max_key_press(9, 0) << '\n';
  std::cout << max_key_press(11, 0) << '\n';
  return 0;
}
