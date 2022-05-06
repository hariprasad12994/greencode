#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cassert>


class Trie {
  private:
    struct TrieNode {
      std::array<TrieNode*, 26> children{nullptr};
      bool is_word;

      TrieNode(): is_word(false) {}
    };
    TrieNode* head;

  public:
    Trie(): head(new TrieNode()) {}

    void insert(const std::string& word) {
      TrieNode* walker = head;

      for(auto const& ch: word) {
        if(walker->children[ch - 'a'] == nullptr) {
          walker->children[ch - 'a'] = new TrieNode();
        }
        walker = walker->children[ch - 'a'];
      }
      walker->is_word = true;
    }

    bool find(const std::string& word) {
      TrieNode* walker = head;
      for(auto const& ch: word) {
        if(walker->children[ch - 'a'] == nullptr) {
          return false;
        }
        walker = walker->children[ch - 'a'];
      }
      return walker->is_word;
    }
};


int main(void) {
  Trie dictionary;
  std::vector<std::string> word_bank{"master", "hello", "world", "bye", "morning"};
  for(auto const& word: word_bank) {
    dictionary.insert(word);
  }

  std::cout << dictionary.find("hello") << '\n';
  std::cout << dictionary.find("world") << '\n';
  std::cout << dictionary.find("king") << '\n';

  return 0;
}
