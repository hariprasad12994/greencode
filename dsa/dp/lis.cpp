#include <iostream>
#include <vector>


int lis(const std::vector<int>& seq, int n, int curr) {
  if(curr == n) return 1;

  auto len_current_included = 0;
  if(seq[curr] < seq[curr + 1])
    len_current_included = 1 + lis(seq, n, curr + 1);
  auto len_current_excluded = lis(seq, n, curr + 1);

  return std::max(len_current_included, len_current_excluded);
}

int lis(const std::vector<int>& seq, int n) {
  return lis(seq, n, 0);
}


int main(void) {
  std::cout << lis(std::vector<int>{10, 22, 9, 33, 21, 50, 41, 60, 80}, 9) << '\n';
  return 0;
}
