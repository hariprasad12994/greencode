#include <vector>
#include <iostream>


int min_element_by_bsearch(const std::vector<int>& nums, std::size_t left_idx, std::size_t right_idx) {
  auto mid_idx = (left_idx + right_idx) / 2;

  if(mid_idx == 0 || mid_idx == nums.size() - 1) 
    return nums[mid_idx];
  if(nums[mid_idx] < nums[mid_idx - 1] && nums[mid_idx + 1] > nums[mid_idx])
    return nums[mid_idx];
  if(nums[right_idx] > nums[mid_idx])
    return min_element_by_bsearch(nums, left_idx, mid_idx - 1);
   return min_element_by_bsearch(nums, mid_idx + 1, right_idx);
}


int min_element_in_sorted_rotated_array(const std::vector<int>& nums) {
  if(nums.size() == 1) 
    return nums[0];
  return min_element_by_bsearch(nums, 0, nums.size() - 1);
}

int main(void) {
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{9}) << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{7, 5, 4, 1, 2}) << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{1, 2, 3, 4, 5}) << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{5, 4, 3, 1}) << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{13, 22, 46, 107, 112, 3, 7}) << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{53, 134, 181, 343, 540, 604, 777, 781, 3, 7, 13, 17, 19}) << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{1, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10, 10, 11}) << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{11, 11, 11, 7, 7, 7, 7, 5, 4, 2, 1, 0}) << '\n';
  return 0;
}
