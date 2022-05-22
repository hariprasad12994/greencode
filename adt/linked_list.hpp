#include <iostream>


template <typename T>
class List;

template <typename T>
void print(const List<T>& list);


template <typename T>
class List {
  public:
    struct LinkedListNode {
      T payload;
      LinkedListNode* next;
      LinkedListNode(const T& payload): payload(payload) {}
    };
    
    friend void print<T>(const List<T>& list);

    List(): head(nullptr), tail(nullptr) {}

    void insert(const T& val, LinkedListNode* other_node) {
      LinkedListNode* new_node = new LinkedListNode(val);
      other_node->next = new_node;
    }

    void remove(const T& val, LinkedListNode* other_node) {
    }


    void push_front(const T& val) {
      LinkedListNode* new_node = new LinkedListNode(val);
      // if list is empty
      if(head == nullptr && tail == nullptr) {
        head = new_node;
        tail = new_node;
        return;
      }
      new_node->next = head;
      head = new_node;
    }

    void push_back(const T& val) {
      LinkedListNode* new_node = new LinkedListNode(val);
      if(head == nullptr && tail == nullptr) {
        head = new_node;
        tail = new_node;
        return;
      }
      tail->next = new_node;
      tail = new_node;
    }

    void pop_front() {
      if(head == nullptr && tail == nullptr) 
        return;

      if(head == tail) {
        LinkedListNode* temp = head;
        head = nullptr;
        tail = nullptr;
        delete temp;
        return;
      }

      LinkedListNode* temp = head;
      head = head->next;
      delete temp;
    }

    void pop_back() {
      if(head == nullptr && tail == nullptr) 
        return;

      if(head == tail) {
        LinkedListNode* temp = head;
        head = nullptr;
        tail = nullptr;
        delete temp;
        return;
      }

      LinkedListNode* temp = tail;
      LinkedListNode* walker = head;
      while(walker->next != tail) {
        walker = walker->next;
      }
      tail = walker;
      tail->next = nullptr;
      delete temp;
    }

    void erase() {
      if(head == nullptr && tail == nullptr) return;
      LinkedListNode* walker = head;
      LinkedListNode* prev_walker = head;
      while(walker != nullptr) {
        walker = prev_walker->next;
        delete prev_walker;
        prev_walker = walker;
      }
      head = nullptr;
      tail = nullptr;
    }

    T& front() { return head->payload; }
    T& back() { return tail->payload; }

    bool empty() { return head == nullptr && tail == nullptr; }

    ~List() { erase(); }

  private:
    LinkedListNode* head;
    LinkedListNode* tail;
};


template <typename T>
void print(const List<T>& list) {
  using ListNode = typename List<T>::LinkedListNode*;
  ListNode walker = list.head;
  while(walker != nullptr) {
    std::cout << walker->payload << " ";
    walker = walker->next;
  }
  std::cout << '\n';
}

