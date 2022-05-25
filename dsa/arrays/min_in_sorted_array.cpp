#include <vector>
#include <iostream>


int min_element_by_bsearch(const std::vector<int>& nums, std::size_t left_idx, std::size_t right_idx) {
  auto mid_idx = (left_idx + right_idx) / 2;
  for(std::size_t iter = left_idx; iter <= right_idx; iter++) std::cout << nums[iter] << " ";
  std::cout << "mid = " << nums[mid_idx] << '\n';

  if(mid_idx == 0 || mid_idx == nums.size() - 1) return nums[mid_idx];
  if(nums[mid_idx] < nums[mid_idx - 1] && nums[mid_idx + 1] > nums[mid_idx])
    return nums[mid_idx];
  if(nums[left_idx] > nums[right_idx])
    return min_element_by_bsearch(nums, mid_idx + 1, right_idx);
  return min_element_by_bsearch(nums, left_idx, mid_idx - 1);
}


int min_element_in_sorted_rotated_array(const std::vector<int>& nums) {
  if(nums.size() == 1) 
    return nums[0];
  return min_element_by_bsearch(nums, 0, nums.size() - 1);
}

int main(void) {
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{9}) << '\n';
  std::cout << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{7, 5, 4, 1, 2}) << '\n';
  std::cout << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{1, 2, 3, 4, 5}) << '\n';
  std::cout << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{5, 4, 3, 1}) << '\n';
  std::cout << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{13, 22, 46, 107, 112, 3, 7}) << '\n';
  std::cout << '\n';
  std::cout << min_element_in_sorted_rotated_array(std::vector<int>{53, 134, 181, 343, 540, 604, 777, 781, 3, 7, 13, 17, 19}) << '\n';
  return 0;
}
