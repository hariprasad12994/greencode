#ifndef _LL_HPP_
#define _LL_HPP_

#include <iostream>

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

template <typename T>
void print_list(LinkedListNode<T>* list) {
  LinkedListNode<T>* walker = list;
  while(walker != nullptr) {
    std::cout << walker->payload << " ";
    walker = walker->next;
  }
  std::cout << '\n';
}

#endif
