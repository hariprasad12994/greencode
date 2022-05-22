#include <iostream>
#include <array>


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


