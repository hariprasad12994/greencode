#include <iostream>
#include "../lib/runtime.hpp"
#include <vector>


int knapsack_bounded(int target_weight, const std::vector<int>& weights, const std::vector<int>& values, int item_idx) {
  if(target_weight <= 0 || item_idx >= values.size()) return 0;

  auto take_away_including_curr_idx = 0;
  if(weights[item_idx] <= target_weight)
    take_away_including_curr_idx = values[item_idx] + knapsack_bounded(target_weight - weights[item_idx], weights, values, item_idx + 1);

  auto take_away_excluding_curr_idx = knapsack_bounded(target_weight, weights, values, item_idx + 1);
  
  return std::max(take_away_including_curr_idx, take_away_excluding_curr_idx);
}

int knapsack_bounded(int target_weight, const std::vector<int>& weights, const std::vector<int>& values) {
  return knapsack_bounded(target_weight, weights, values, 0);
}

int knapsack_unbounded(int target_weight, const std::vector<int>& weights, const std::vector<int>& values, int item_idx) {
  if(target_weight <= 0 || item_idx >= values.size()) return 0;

  auto take_away_including_curr_idx = 0;
  if(weights[item_idx] <= target_weight)
    take_away_including_curr_idx = values[item_idx] + knapsack_unbounded(target_weight - weights[item_idx], weights, values, item_idx);

  auto take_away_excluding_curr_idx = knapsack_unbounded(target_weight, weights, values, item_idx + 1);
  
  return std::max(take_away_including_curr_idx, take_away_excluding_curr_idx);
}

int knapsack_unbounded(int target_weight, const std::vector<int>& weights, const std::vector<int>& values) {
  return knapsack_unbounded(target_weight, weights, values, 0);
}

int main(void) {
  std::cout << knapsack_bounded(50, std::vector<int>{10, 20, 30}, std::vector<int>{60, 100, 120}) << '\n';
  std::cout << knapsack_bounded(7, std::vector<int>{1, 2, 3, 5}, std::vector<int>{1, 6, 10, 16}) << '\n';
  std::cout << knapsack_unbounded(100, std::vector<int>{1, 50}, std::vector<int>{1, 30}) << '\n';
  std::cout << knapsack_unbounded(8, std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}, std::vector<int>{1, 5, 8, 9, 10, 17, 17, 20}) << '\n';
  std::cout << knapsack_unbounded(8, std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}, std::vector<int>{3, 5, 8, 9, 10, 17, 17, 20}) << '\n';

  return 0;
}
