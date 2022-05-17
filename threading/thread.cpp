#include <mutex>
#include <thread>
#include <iostream>


int main() {
  auto counter = 0;
  std::mutex critical_section;

  std::thread increment_thread([&](){ 
    auto iterations = 0;
    for(iterations = 1; iterations <= 100; iterations++)
      {
        std::unique_lock lock(critical_section);
        counter++; 
      }
  });

  std::thread decrement_thread([&](){ 
    auto iterations = 0;
    for(iterations = 1; iterations <= 100; iterations++)
      {
        std::unique_lock lock(critical_section);
        counter--; 
      }
  });

  increment_thread.join();
  decrement_thread.join();

  std::cout << counter << '\n';

  return 0;
}
