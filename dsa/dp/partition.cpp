#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>


int partition(const std::vector<int>& input, int sum, int target, std::size_t running_len, std::size_t curr_idx) {
  // base case: if sum is greater than half of the target sum
  // base case: if size of subset A is greater than or equal to subset B
  if(curr_idx == input.size()) {
    // std::cout << sum << " " << running_len << " " << std::ceil(static_cast<double>(target) / 2) << " " << std::ceil(static_cast<double>(input.size()) / 2) << '\n';
    if(sum > std::ceil(static_cast<double>(target) / 2) && 
       running_len < std::ceil(static_cast<double>(input.size()) / 2)) 
        return 1;
    else return 0;
  }

  auto way_1 = partition(input, sum + input[curr_idx], target, running_len + 1, curr_idx + 1);
  auto way_2 = partition(input, sum, target, running_len, curr_idx + 1);

  return way_1 + way_2;
}

int partition(const std::vector<int>& input) {
  return partition(input, 0, std::accumulate(input.begin(), input.end(), 0), 0, 0);
}


int main(void) {
  std::cout << partition(std::vector<int>{1, 5, 3}) << '\n';
  std::cout << partition(std::vector<int>{1, 11, 3}) << '\n';
  std::cout << partition(std::vector<int>{3, 4, 6, 7}) << '\n';
  std::cout << partition(std::vector<int>{3, 4, 6, 11}) << '\n';
  std::cout << partition(std::vector<int>{3, 1, 6, 11}) << '\n';
  std::cout << partition(std::vector<int>{3, 1, 6, 7}) << '\n';
  std::cout << partition(std::vector<int>{3, 1, 6, 19}) << '\n';
  return 0;
}
