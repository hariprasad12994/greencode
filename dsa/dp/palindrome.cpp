#include <string>
#include <iostream>

/*
abcd -> False
tacocats -> True
racercar -> True
*/


bool can_be_made_palindrome(const std::string& input, std::size_t left_idx, std::size_t right_idx) {
  if(left_idx >= right_idx) return false;

  if(input[left_idx] == input[right_idx]) 
    return true || can_be_made_palindrome(input, left_idx + 1, right_idx - 1);

  return can_be_made_palindrome(input, left_idx + 1, right_idx) || can_be_made_palindrome(input, left_idx, right_idx - 1);
}

bool can_be_made_palindrome(const std::string& input) {
  return can_be_made_palindrome(input, 0, input.size() - 1);
}

int main(void) {
  std::cout << can_be_made_palindrome("abcd") << '\n';
  std::cout << can_be_made_palindrome("tacocats") << '\n';
  std::cout << can_be_made_palindrome("racercar") << '\n';
  return 0;
}
