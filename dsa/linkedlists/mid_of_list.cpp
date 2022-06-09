#include <iostream>

#include "ll.hpp"


template <typename T>
T mid_of_list(LinkedListNode<T>* head) {
  LinkedListNode<T>* fast = head;
  LinkedListNode<T>* slow = head;

  while(slow != nullptr && fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->payload;
}

int main(void) {
  LinkedListNode<int>* head = new_node<int>(0);
  LinkedListNode<int>* _1 = new_node<int>(1);
  LinkedListNode<int>* _2 = new_node<int>(2);
  LinkedListNode<int>* _3 = new_node<int>(3);
  LinkedListNode<int>* _4 = new_node<int>(4);
  LinkedListNode<int>* _5 = new_node<int>(5);

  head->next = _1;
  _1->next = _2;
  _2->next = _3;
  _3->next = _4;
  _4->next = _5;

  int mid_elem = mid_of_list<int>(head);
  std::cout << mid_elem << '\n';

  return 0;
}
