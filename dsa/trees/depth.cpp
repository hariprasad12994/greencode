#include "../../adt/tree.hpp"
#include <iostream>


template <typename T>
std::size_t depth(TreeNode<T>* root) {
  if(root == nullptr)
    return 0;
  std::size_t height_left = 1 + depth(root->left);
  std::size_t height_right = 1 + depth(root->right);
  return std::max(height_left, height_right);
}


int main(void) {
  TreeNode<int>* root = new_node<int>(1);
  TreeNode<int>* _2 = new_node<int>(2);
  TreeNode<int>* _3 = new_node<int>(3);
  TreeNode<int>* _4 = new_node<int>(4);
  TreeNode<int>* _5 = new_node<int>(5);

  root->left = _2;
  root->right = _3;
  _3->left = _4;
  _3->right = _5;

  std::cout << depth(root) << '\n';

  TreeNode<int>* another_tree = new_node<int>(1);
  TreeNode<int>* _2b = new_node<int>(2);
  TreeNode<int>* _3b = new_node<int>(3);
  TreeNode<int>* _4b = new_node<int>(4);
  another_tree->left = _2b;
  _2b->left = _3b;
  _3b->left = _4b;
  std::cout << depth(another_tree) << '\n';

  return 0;
}
