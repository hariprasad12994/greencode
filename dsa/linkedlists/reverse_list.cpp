#include "ll.hpp"
#include <iostream>


template <typename T>
LinkedListNode<T>* reverse(LinkedListNode<T>* head) {
  LinkedListNode<T>* new_head = nullptr, *temp = nullptr;
  LinkedListNode<T>* walker = head;

  while(walker != nullptr) {
    temp = walker->next;
    walker->next = new_head;
    new_head = walker;
    walker = temp;
  }

  return new_head;
}


template <typename T>
void print_list(LinkedListNode<T>* list) {
  LinkedListNode<T>* walker = list;
  while(walker != nullptr) {
    std::cout << walker->payload << '\n';
    walker = walker->next;
  }
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

  LinkedListNode<int>* rev_list = reverse(head);
  print_list<int>(rev_list);

  return 0;
}
