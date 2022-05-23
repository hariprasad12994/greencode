#include <iostream>
#include <vector>


int max_profit(const std::vector<int>& prices) {
  if(prices.size() == 1) 
    return 0;

  std::vector<int> local_maximums(prices.size(), 0);
  std::vector<int> local_minimums(prices.size(), 0);
  int maximum_profit = 0;

  local_minimums[0] = prices[0];
  for(int idx = 1; idx < prices.size(); idx++) {
    local_minimums[idx] = local_minimums[idx - 1] > prices[idx] ? prices[idx] : local_minimums[idx - 1];
  }

  local_maximums[prices.size() - 1] = prices[prices.size() - 1];
  for(int idx = prices.size() - 2; idx >= 0 ; idx--) {
    local_maximums[idx] = local_maximums[idx + 1] < prices[idx] ? prices[idx] : local_maximums[idx + 1];
  }

  for(int idx = 0; idx < prices.size(); idx++) {
    if(maximum_profit < local_maximums[idx] - local_minimums[idx])
      maximum_profit = local_maximums[idx] - local_minimums[idx];
  }

  return maximum_profit;
}


int main(void) {
  std::cout << max_profit(std::vector<int>{7, 1, 5, 3, 6, 4}) << '\n';
  std::cout << max_profit(std::vector<int>{7, 6, 5, 3, 2, 1}) << '\n';
  return 0;
}
