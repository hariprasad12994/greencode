#include <iostream>
#include <algorithm>
#include <string>
#include <map>

struct Index {
public:
  int idx_1;
  int idx_2;
  Index(int idx_1_, int idx_2_): idx_1(idx_1_), idx_2(idx_2_) {}
  friend bool operator<(const Index& lhs, const Index& rhs) {
    return lhs.idx_1 < rhs.idx_1 || (lhs.idx_1 == rhs.idx_1 && lhs.idx_2 < rhs.idx_2);
  }
};


unsigned int lcs_memo(const std::string& seq_1, const std::string& seq_2, std::size_t seq_1_idx, std::size_t seq_2_idx, std::map<Index, int>& memo) {
  Index idx(seq_1_idx, seq_2_idx);

  if(memo.find(idx) != memo.end()) return memo[idx];

  if(seq_1_idx == 0 || seq_2_idx == 0) return 0;

  if(seq_1.at(seq_1_idx - 1) == seq_2.at(seq_2_idx - 1)) {
    memo[idx] = 1 + lcs_memo(seq_1, seq_2, seq_1_idx - 1, seq_2_idx - 1, memo);
    return memo[idx];
  }

  memo[idx] = std::max(lcs_memo(seq_1, seq_2, seq_1_idx - 1, seq_2_idx, memo),
                       lcs_memo(seq_1, seq_2, seq_1_idx, seq_2_idx - 1, memo));
  return memo[idx];
}

unsigned int lcs_memo(const std::string& seq_1, const std::string& seq_2, std::size_t seq_1_idx, std::size_t seq_2_idx){
  std::map<Index, int> memo;
  return lcs_memo(seq_1, seq_2, seq_1_idx, seq_2_idx, memo);
}

unsigned int lcs(const std::string& seq_1, const std::string& seq_2, std::size_t seq_1_idx, std::size_t seq_2_idx){
  if(seq_1_idx == 0 || seq_2_idx == 0) return 0;

  if(seq_1.at(seq_1_idx - 1) == seq_2.at(seq_2_idx - 1))
    return 1 + lcs(seq_1, seq_2, seq_1_idx - 1, seq_2_idx - 1);

  return std::max(lcs(seq_1, seq_2, seq_1_idx - 1, seq_2_idx),
                  lcs(seq_1, seq_2, seq_1_idx, seq_2_idx - 1));
}

int main(void){
  std::cout << lcs(std::string("ABDACDA"), std::string("ABADCE"), 7, 6) << '\n';
  std::cout << lcs(std::string("aggtab"), std::string("gxtxayb"), 6, 7) << '\n';
  std::cout << lcs(std::string("ABAA"), std::string("ABADCE"), 4, 6) << '\n';

  std::cout << lcs_memo(std::string("ABDACDA"), std::string("ABADCE"), 7, 6) << '\n';
  std::cout << lcs_memo(std::string("aggtab"), std::string("gxtxayb"), 6, 7) << '\n';
  std::cout << lcs_memo(std::string("ABAA"), std::string("ABADCE"), 4, 6) << '\n';

  return 0;
}

