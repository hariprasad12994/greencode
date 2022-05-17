#include <thread>
#include <mutex>
#include <condition_variable>
#include <numeric>

#include <vector>
#include <algorithm>

#include <iostream>


int main(void) {
  std::vector<int> data_packet(8, 0);
  std::mutex critical_section;
  std::condition_variable packet_dispatch_barrier;
  bool packet_dispatched = false;
  bool packet_processed = false;

  std::thread producer_thread(
    [&](){
      std::iota(data_packet.begin(), data_packet.end(), 0);
      std::for_each(data_packet.begin(), data_packet.end(), [](auto elem) { std::cout << elem << " "; });
      std::cout << '\n';
      packet_dispatched = true;
      packet_dispatch_barrier.notify_one();
    }
  );

  std::thread consumer_thread(
    [&](){
      std::unique_lock lock(critical_section);
      packet_dispatch_barrier.wait(lock, [&](){ return packet_dispatched; });
      std::transform(data_packet.begin(), data_packet.end(), data_packet.begin(), [](auto elem) { return elem * 2; });
      std::for_each(data_packet.begin(), data_packet.end(), [](auto elem) { std::cout << elem << " "; });
      std::cout << '\n';
      packet_processed = true;
    }
  );

  producer_thread.join();
  consumer_thread.join();

  return 0;
}

