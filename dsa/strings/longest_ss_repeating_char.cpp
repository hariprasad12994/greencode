#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


std::size_t longest_ss_repeating_char(const std::string& input) {
  if(input.size() == 0) return 0;
  if(input.size() == 1) return 1;

  std::vector<std::size_t> char_count_map(26, 0);
  std::size_t left_idx = 0, right_idx = 0;
  std::size_t running_len = 0, max_len = 0;

  while(right_idx < input.size()){
    char_count_map[input[right_idx] - 97]++;
    if(std::any_of(char_count_map.begin(), char_count_map.end(), [](auto elem) { return elem > 1; })) {
      if(max_len < running_len)
        max_len = running_len;
      std::fill(char_count_map.begin(), char_count_map.end(), 0);
      running_len = 0;
    }
    else {
      running_len++;
      right_idx++;
    }
  }

  return max_len;
}


int main(void) {
  std::cout << longest_ss_repeating_char("abcabcbb") << '\n';
  std::cout << longest_ss_repeating_char("bbbbb") << '\n';
  std::cout << longest_ss_repeating_char("pwwkew") << '\n';
  return 0;
}
