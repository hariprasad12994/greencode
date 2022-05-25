#include <vector>
#include <iostream>


std::size_t min_element_idx(const std::vector<int>& nums, std::size_t left_idx, std::size_t right_idx) {
  auto mid_idx = (left_idx + right_idx) / 2;

  if(mid_idx == 0 || mid_idx == nums.size() - 1) 
    return mid_idx;
  if(nums[mid_idx] < nums[mid_idx - 1] && nums[mid_idx + 1] > nums[mid_idx])
    return mid_idx;
  if(nums[right_idx] > nums[mid_idx])
    return min_element_idx(nums, left_idx, mid_idx - 1);
   return min_element_idx(nums, mid_idx + 1, right_idx);
}


int median_in_sorted_rotated_array(const std::vector<int>& nums) {
  if(nums.size() == 1) 
    return nums[0];
  auto pivot_idx = min_element_idx(nums, 0, nums.size() - 1);
  if(nums.size() % 2 != 0)
    return nums[(pivot_idx + nums.size() / 2) % nums.size()];
  auto first = nums[(pivot_idx + nums.size() / 2) % nums.size()];
  auto second = nums[(pivot_idx + nums.size() / 2 + 1) % nums.size()];
  return (first + second) / 2;
}

int main(void) {
  std::cout << median_in_sorted_rotated_array(std::vector<int>{9}) << '\n';
  std::cout << median_in_sorted_rotated_array(std::vector<int>{4, 5, 7, 1, 2}) << '\n';
  std::cout << median_in_sorted_rotated_array(std::vector<int>{1, 2, 3, 4, 5}) << '\n';
  std::cout << median_in_sorted_rotated_array(std::vector<int>{3, 4, 5, 1}) << '\n';
  std::cout << median_in_sorted_rotated_array(std::vector<int>{13, 22, 46, 107, 112, 3, 7}) << '\n';
  std::cout << median_in_sorted_rotated_array(std::vector<int>{53, 134, 181, 343, 540, 604, 777, 781, 3, 7, 13, 17, 19}) << '\n';
  std::cout << median_in_sorted_rotated_array(std::vector<int>{1, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10, 10, 11}) << '\n';
  std::cout << median_in_sorted_rotated_array(std::vector<int>{11, 11, 11, 7, 7, 7, 7, 5, 4, 2, 1, 0}) << '\n';
  return 0;
}
