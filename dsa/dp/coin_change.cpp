#include <iostream>
#include <vector>


int coin_change(const std::vector<int>& coins, int target, std::size_t curr_idx) {
  if(curr_idx >= coins.size()) return 0;
  if(target == 0) return 1;

  auto ways_including_curr_coin = 0;
  if(coins[curr_idx] <= target)
    ways_including_curr_coin = coin_change(coins, target - coins[curr_idx], curr_idx);
  auto ways_excluding_curr_coin = coin_change(coins, target, curr_idx + 1);

  return ways_including_curr_coin + ways_excluding_curr_coin;
}


int coin_change(const std::vector<int>& coins, int value) {
  return coin_change(coins, value, 0);
}


int coin_change_tabulation(const std::vector<int>& coins, int value) {
  std::vector<std::vector<int>> table(coins.size() + 1, std::vector<int>(value + 1, 0));
  
  for(std::size_t coin = 0; coin <= coins.size(); coin++) {
    for(std::size_t amount = 0; amount <= value; amount++) {
      if(coin == 0) table[coin][amount] = 1;
      else if(amount == 0) table[coin][amount] = 0;
      else{
        if(coins[coin - 1] > amount) {
          table[coin][amount] = table[coin - 1][amount - 1];
        }
        else {
          table[coin][amount] = 1 + table[coin - 1][amount - 1];
        }
      }
    }
  }

  for(auto row: table) {
      for(auto elem: row) {
          std::cout << elem << " ";
      }
      std::cout << '\n';
  }

  return table[coins.size()][value];
}


int main(void) {
  std::cout << coin_change(std::vector<int>{1, 2, 3}, 4) << '\n';
  std::cout << coin_change(std::vector<int>{2, 5, 3, 6}, 10) << '\n';
  std::cout << coin_change_tabulation(std::vector<int>{1, 2, 3}, 4) << '\n';
  std::cout << coin_change_tabulation(std::vector<int>{2, 5, 3, 6}, 10) << '\n';
  return 0;
}
