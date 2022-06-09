#ifndef _TREE_H_
#define _TREE_H_

template <typename T>
struct TreeNode {
  T payload;
  TreeNode* left;
  TreeNode* right;
  TreeNode(T payload): payload(payload), left(nullptr), right(nullptr) {}
};

template <typename T>
TreeNode<T>* new_node(T payload) {
  return new TreeNode<T>(payload);
}

#endif
