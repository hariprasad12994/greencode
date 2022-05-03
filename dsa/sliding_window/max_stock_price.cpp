#include <iostream>
#include <vector>
#include <limits>


int max_stock_price(const std::vector<int>& prices) {
  std::size_t min_index = 0;
  std::size_t max_index = price.size() - 1;
  std::size_t left_ptr = 0;
  std::size_t right_ptr = prices.size() - 1;

  while(min_index > max_index) {
    if(prices[left_idx] > prices[right_idx]) {
      while(prices[left_idx] > prices[right_idx]) left_idx++;
    }
    else if(prices[left_idx] < prices[right_idx]) {
      while(prices[left_idx] >
    }
    min_index = left_ptr;
    max_index = right_ptr;
  }

  if(min_index > max_index) return 0;
  return prices[max_index - min_index];
}


int main(void) {
  return 0;
}
