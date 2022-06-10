#include "ll.hpp"
#include <iostream>


template <typename T>
LinkedListNode<T>* merge(LinkedListNode<T>* head_1, LinkedListNode<T>* head_2) {
  if(head_1 == nullptr && head_2 == nullptr)
    return nullptr;

  if(head_1 == nullptr)
    return head_2;

  if(head_2 == nullptr)
    return head_1;

  LinkedListNode<T>* merged = nullptr;
  if(head_1->payload > head_2->payload) {
    merged = head_1;
    head_1 = head_1->next;
  }
  else {
    merged = head_2;
    head_2 = head_2->next;
  }

  LinkedListNode<T>* tail = merged;
  while(head_1 != nullptr && head_2 != nullptr) {
    if(head_1->payload == head_2->payload) {
      LinkedListNode<T>* temp = head_1->next;
      tail->next = head_1;
      head_1->next = head_2;
      head_1 = temp;
      head_2 = head_2->next;
    }
    else if(head_1->payload < head_2->payload) {
      tail->next = head_1;
      head_1 = head_1->next;
      tail = tail->next;
    }
    else {
      tail->next = head_2;
      head_2 = head_2->next;
      tail = tail->next;
    }
  }

  if(head_1 != nullptr) tail->next = head_1;
  if(head_2 != nullptr) tail->next = head_2;

  return merged;
}


int main(void) {
  LinkedListNode<int>* head_1 = new_node<int>(0);
  LinkedListNode<int>* head_2 = new_node<int>(0);
  LinkedListNode<int>* _1 = new_node<int>(1);
  LinkedListNode<int>* _2 = new_node<int>(2);
  LinkedListNode<int>* _3 = new_node<int>(3);
  LinkedListNode<int>* _4 = new_node<int>(4);
  LinkedListNode<int>* _5 = new_node<int>(5);
  LinkedListNode<int>* _6 = new_node<int>(6);
  LinkedListNode<int>* _7 = new_node<int>(7);
  LinkedListNode<int>* _8 = new_node<int>(8);
  LinkedListNode<int>* _9 = new_node<int>(9);
  LinkedListNode<int>* _10 = new_node<int>(10);
  LinkedListNode<int>* _11 = new_node<int>(11);

  head_1->next = _1;
  _1->next = _3;
  _3->next = _5;
  _5->next = _7;
  _7->next = _9;
  _9->next = _11;

  head_2->next = _2;
  _2->next = _4;
  _4->next = _6;
  _6->next = _8;
  _8->next = _10;

  LinkedListNode<int>* merged = merge(head_1, head_2);
  print_list<int>(merged);

  merged = merge<int>(nullptr, nullptr);
  print_list<int>(merged);

  LinkedListNode<char>* c_head_1 = new_node<char>('s');
  LinkedListNode<char>* c_merged = merge<char>(c_head_1, nullptr);
  print_list<char>(c_merged);
  LinkedListNode<char>* c_head_2 = new_node<char>('f');
  c_merged = merge<char>(nullptr, c_head_2);
  print_list<char>(c_merged);

  return 0;
}
