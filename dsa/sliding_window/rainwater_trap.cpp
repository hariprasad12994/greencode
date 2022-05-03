#include <deque>
#include <iostream>
#include <vector>


int rainwater_trap(const std::vector<int>& bars) {
  int volume = 0;

  std::deque<int> bar_queue;
  bar_queue.push_back(bars[0]);
  
  std::cout << "if((bar_queue.front() <= *iter) || (bar_queue.front() > bar_queue.back() && bar_queue.back() >= *iter)) {" << '\n';
  for(auto iter = bars.begin() + 1; iter != bars.end(); iter++) {
    if(bar_queue.empty()) break;
    
    std::cout << "Front = " << bar_queue.front() << " Back = " << bar_queue.back() << " Next = " << *iter << '\n';
    if((bar_queue.front() <= *iter) || (bar_queue.front() > bar_queue.back() && bar_queue.back() >= *iter)) {
      std::cout << "Here\n";
      auto max_height = bar_queue.front();
      while(!bar_queue.empty()) {
        volume = volume + (max_height - bar_queue.front());
        bar_queue.pop_front();
      }
    }

    bar_queue.push_back(*iter);
  }

  return volume;
}


int main(void) { 
  std::cout << rainwater_trap(std::vector<int>{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << '\n';
  return 0;
}
