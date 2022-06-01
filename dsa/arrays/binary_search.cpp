#include <iostream>
#include <vector>


int binary_search(const std::vector<int>& nums, int key, std::size_t left, std::size_t right) {
  if(left >= right) return -1;

  auto mid = (left + right) / 2;
  if(nums[mid] == key) return mid;
  if(nums[mid] > key) 
    return binary_search(nums, key, mid + 1, right);
  return binary_search(nums, key, left, mid - 1);
}


int binary_search(const std::vector<int>& nums, int key) {
  return binary_search(nums, key, 0, nums.size() - 1);
}


int main(void) {
  std::cout << binary_search(std::vector<int>{8, 9, 15, 65, 109, 111, 203}, 76) << '\n';
  std::cout << binary_search(std::vector<int>{8, 9, 15, 65, 109, 111, 203}, 65) << '\n';
  return 0;
}
