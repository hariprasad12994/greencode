#include <iostream>
#include <string>



int num_of_decoding_tabulation(const std::string& s) {
  std::vector<int> decoding_count(s.size() + 1, 0);
  for(std::size_t iter = 1; iter <= s.size(); iter++) {
    
  }
  return decoding_count[s.size()];
}


int num_of_decodings(const std::string& s, std::size_t curr_idx){
    if(curr_idx == s.size()) return 1;
    if(curr_idx > s.size()) return 0;
    
    auto decode_with_two_digits = 0;
    auto decode_with_one_digit = 0;
    
    if((s[curr_idx] - 48 == 1) || (s[curr_idx] - 48 == 2) && (s[curr_idx + 1] - 48 < 7))
        decode_with_two_digits = num_of_decodings(s, curr_idx + 2);
    
    if(s[curr_idx] - 48 > 0)
        decode_with_one_digit = num_of_decodings(s, curr_idx + 1);
    
    return decode_with_two_digits + decode_with_one_digit;
}

int num_of_decodings(const std::string& s) {
    return num_of_decodings(s, 0);
}

int main(void) {
  std::cout << num_of_decodings("2611055971756562") << '\n';
  std::cout << num_of_decodings("12") << '\n';
  std::cout << num_of_decodings("226") << '\n';
  return 0;
}
