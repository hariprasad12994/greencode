#include <iostream>
#include <map>
#include <vector>
#include "../lib/runtime.hpp"


int count_step_climb_paths_tabulation(int n, std::vector<int>& table, const std::vector<int>& steps) {
  for(auto iter = 0; iter <= n; iter++) {
      for(auto step: steps) {
        if(iter + step <= n) {
          table[iter + step] += table[iter];
        }
      }
  }

  return table[n];
}


int count_step_climb_paths_tabulation(int n) {
  std::vector<int> table(n + 1, 0);
  std::vector<int> steps = {1, 2, 3};

  table[0] = 1;

  return count_step_climb_paths_tabulation(n, table, steps);
}

int count_step_climb_paths_memo_intern(int n, std::map<int, int>& memo) {
  if(memo.find(n) != memo.end()) return memo.at(n);
  if(n < 0) return 0;
  if(n == 0) return 1;

  memo[n] =  count_step_climb_paths_memo_intern(n - 1, memo) +
             count_step_climb_paths_memo_intern(n - 2, memo) +
             count_step_climb_paths_memo_intern(n - 3, memo);
  return memo[n];
}


int count_step_climb_paths_memo(int n) {
  std::map<int, int> memo;
  return count_step_climb_paths_memo_intern(n, memo); 
}


int count_step_climb_paths(int n) {
  if(n == 0) return 1;
  if(n < 0) return 0;

  return count_step_climb_paths(n - 1) +
         count_step_climb_paths(n - 2) +
         count_step_climb_paths(n - 3);
}


int main(void) {
  std::vector<int> inputs{0, 2, 4, 5, 10, 20, 30};

  std::cout << "Brute Force" << '\n';
  for(auto input: inputs) {
    {
      RuntimeMeasurement rm;
      std::cout << "Input = " << input << " Output = " << count_step_climb_paths(input) << '\n';
    }
  }
  std::cout << '\n';

  std::cout << "Memoized" << '\n';
  for(auto input: inputs) {
    {
      RuntimeMeasurement rm;
      std::cout << "Input = " << input << " Output = " << count_step_climb_paths_memo(input) << '\n';
    }
  }
  std::cout << '\n';

  std::cout << "Tabulation" << '\n';
  for(auto input: inputs) {
    {
      RuntimeMeasurement rm;
      std::cout << "Input = " << input << " Output = " << count_step_climb_paths_tabulation(input) << '\n';
    }
  }
  std::cout << '\n';

  return 0;
}
