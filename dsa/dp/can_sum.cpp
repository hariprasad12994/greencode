#include <iostream>
#include "../lib/runtime.hpp"
#include <vector>


bool can_sum(const std::vector<int>& nums, int target_sum) {
  if(target_sum == 0) return true;
  if(target_sum < 0)  return false;

  bool is_possible = false;

  for(auto const& num: nums) is_possible  = is_possible || can_sum(nums, target_sum - num);

  return is_possible;
}


int main(void) {
  std::cout << can_sum(std::vector<int>{5, 3, 4, 7}, 7) << '\n';
  std::cout << can_sum(std::vector<int>{5, 3, 4, 7}, 2) << '\n';
  std::cout << can_sum(std::vector<int>{5, 3, 4, 7}, 13) << '\n';
  std::cout << can_sum(std::vector<int>{5, 3, 4, 7}, 12) << '\n';
  std::cout << can_sum(std::vector<int>{5, 3, 8, 7}, 9) << '\n';
  std::cout << can_sum(std::vector<int>{2, 4}, 9) << '\n';
  std::cout << can_sum(std::vector<int>{7, 14}, 9) << '\n';
  std::cout << can_sum(std::vector<int>{7, 14}, 100) << '\n';
  std::cout << can_sum(std::vector<int>{7, 14}, 300) << '\n';
  return 0;
}
