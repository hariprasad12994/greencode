#include "../../adt/tree.hpp"
#include <iostream>


template <typename T>
void inorder(TreeNode<T>* root) {
  if(root == nullptr)
    return;
  inorder(root->left);
  std::cout << root->payload << " ";
  inorder(root->right);
}

template <typename T>
void preorder(TreeNode<T>* root) {
  if(root == nullptr)
    return;
  std::cout << root->payload << " ";
  preorder(root->left);
  preorder(root->right);
}

template <typename T>
void postorder(TreeNode<T>* root) {
  if(root == nullptr)
    return;
  postorder(root->left);
  postorder(root->right);
  std::cout << root->payload << " ";
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

  inorder(root);
  std::cout << '\n';
  preorder(root);
  std::cout << '\n';
  postorder(root);
  std::cout << '\n';

  return 0;
}
