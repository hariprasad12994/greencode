#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>


template <typename T>
void print_min_heap(std::priority_queue<T, std::vector<int>, std::greater<T>> heap) {
  std::cout << "min = ";
  while(!heap.empty()) {
    std::cout << heap.top() << " ";
    heap.pop();
  }
  std::cout << '\n';
}

template <typename T>
void print_max_heap(std::priority_queue<T, std::vector<int>, std::less<T>> heap) {
  std::cout << "max = ";
  while(!heap.empty()) {
    std::cout << heap.top() << " ";
    heap.pop();
  }
  std::cout << '\n';
}

template <typename T>
void clear_min_heap(std::priority_queue<T, std::vector<int>, std::greater<T>>& heap) {
  while(!heap.empty()) {
    heap.pop();
  }
}

template <typename T>
void clear_max_heap(std::priority_queue<T, std::vector<int>, std::less<T>>& heap) {
  while(!heap.empty()) {
    heap.pop();
  }
}

int main(void) {
  std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  std::vector<int> vec{9, 3, 2, 7, 10, 1, 4};
  
  std::for_each(vec.begin(), vec.end(), [&min_heap, &max_heap](auto const& elem) {
    max_heap.push(elem);
    if(!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
      auto max = max_heap.top();
      max_heap.pop();
      min_heap.push(max);
    }

    if(max_heap.size() > min_heap.size() + 1) {
      auto max = max_heap.top();
      max_heap.pop();
      min_heap.push(max);
    }
    else if(max_heap.size() < min_heap.size() + 1) {
      auto min = min_heap.top();
      min_heap.pop();
      max_heap.push(min);
    }

    print_min_heap(min_heap);
    print_max_heap(max_heap);

    if(max_heap.size() > min_heap.size()) std::cout << "Median = " << max_heap.top() << '\n';
    else if(max_heap.size() < min_heap.size()) std::cout << "Median = " << min_heap.top() << '\n';
    else std::cout << "Median = " << (max_heap.top() + min_heap.top()) / 2 << '\n';
  });

  return 0;
}
