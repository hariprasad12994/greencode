#include "ll.hpp"
#include <iostream>


template <typename T>
LinkedListNode<T>* mid_of_list(LinkedListNode<T>* head) {
  LinkedListNode<T>* l_fast = head;
  LinkedListNode<T>* l_slow = head;

  while(l_slow != nullptr && l_fast != nullptr && l_fast->next != nullptr) {
    l_slow = l_slow->next;
    l_fast = l_fast->next->next;
  }

  return l_slow;
}


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
  
  print_list<T>(merged);
  return merged;
}


template <typename T>
LinkedListNode<T>* sort(LinkedListNode<T>* head) {
  if(head == nullptr || head->next == nullptr)
    return head;

  LinkedListNode<T>* mid = mid_of_list(head);
  LinkedListNode<T>* next_head = mid->next;
  mid->next = nullptr;
  return merge(sort(head), sort(next_head));
}


int main(void) {
  LinkedListNode<int>* __1 = new_node<int>(-1);
  LinkedListNode<int>* _0 = new_node<int>(0);
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

  _1->next = _3;
  _3->next = _5;
  _5->next = _7;
  _7->next = _9;
  _9->next = _11;
  _11->next = __1;
  __1->next = _2;
  _2->next = _4;
  _4->next = _6;
  _6->next = _8;
  _8->next = _10;
  _10->next = _0;
  print_list<int>(_1);
  LinkedListNode<int>* sorted = sort(_1);
  print_list<int>(sorted);

  sorted = sort<int>(nullptr);
  print_list<int>(sorted);

  return 0;
}
