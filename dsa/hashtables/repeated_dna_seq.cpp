#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include <iostream>


std::vector<std::string> repeated_dna_seq(const std::string& dna_string, std::size_t window_size) {
  if(dna_string == "") return std::vector<std::string>();
  if(dna_string.size() < window_size) return std::vector<std::string>();

  std::unordered_map<std::string, std::size_t> dna_substring_count;
  std::size_t idx = 0;
  while(idx < dna_string.size() - window_size) {
    auto curr_substring = dna_string.substr(idx, window_size);
    if(dna_substring_count.find(curr_substring) == dna_substring_count.end()) {
      dna_substring_count[curr_substring] = 0;
    }
    dna_substring_count[curr_substring]++;
    idx++;
  }

  std::vector<std::string> res;
  std::for_each(dna_substring_count.cbegin(), dna_substring_count.cend(),
                [&res](auto hash_table_entry) { 
                  if(hash_table_entry.second > 1)
                    res.push_back(hash_table_entry.first);
                });
  return res;
}

int main(void) {
  std::vector<std::string> res;

  res = repeated_dna_seq("", 10);
  std::for_each(res.cbegin(), res.cend(), [](auto substr){ std::cout << substr << " "; });
  std::cout << '\n';

  res = repeated_dna_seq("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", 10);
  std::for_each(res.cbegin(), res.cend(), [](auto substr){ std::cout << substr << " "; });
  std::cout << '\n';

  res = repeated_dna_seq("AAAAAAAAAAAAA", 10);
  std::for_each(res.cbegin(), res.cend(), [](auto substr){ std::cout << substr << " "; });
  std::cout << '\n';

  return 0;
}
