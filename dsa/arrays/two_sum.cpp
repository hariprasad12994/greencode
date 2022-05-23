#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

std::pair<int, int> two_sum(const std::vector<int>& nums, int target) {
  std::unordered_map<int, int> visited;
  std::pair<int, int> res;
  
  for(int idx = 0; idx < nums.size(); idx++) {
    if(visited.find(target - nums[idx]) != visited.end()) {
      res.first = idx;
      res.second = visited[target - nums[idx]];
      break;
    } 
    visited[nums[idx]] = idx;
  }
  
  return res;
}


int main(void) {
  std::pair<int, int> res;

  res = two_sum(std::vector<int>{2, 7, 11, 15}, 9);
  std::cout << res.first << ", " << res.second << '\n';

  //std::cout << two_sum(std::vector<int>{3, 2, 4}, 6) << '\n';

  //std::cout << two_sum(std::vector<int>{3, 3}, 6) << '\n';

  return 0;
}


