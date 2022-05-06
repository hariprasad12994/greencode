#include <iostream>
#include <vector>


int paint_houses(const std::vector<std::vector<int>>& costs, std::size_t house_idx, std::size_t cost_idx) {
  if(house_idx >= costs.size() || cost_idx >= costs[0].size()) return 0;

  std::cout << house_idx << " " << cost_idx <<'\n';

  return std::min(costs[house_idx][cost_idx] + paint_houses(costs, house_idx + 1, cost_idx + 1),
                  paint_houses(costs, house_idx, cost_idx + 1));
}


int paint_houses(const std::vector<std::vector<int>>& costs) {
  return paint_houses(costs, 0, 0);
}


int main(void) {
  std::cout << paint_houses(std::vector<std::vector<int>>{
    {17, 2, 17}, {16, 16, 5}, {14, 3, 19}
  }) << '\n';
  return 0;
}
