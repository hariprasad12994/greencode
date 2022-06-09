#ifndef _LL_HPP_
#define _LL_HPP_

template <typename T>
struct LinkedListNode {
  T payload;
  LinkedListNode* next;
  LinkedListNode(T payload): payload(payload) {}
};


template <typename T>
LinkedListNode<T>* new_node(T payload) {
  return new LinkedListNode<T>(payload);
}

#endif
