#include <chrono>
#include <iostream>


struct RuntimeMeasurement {
public:
  using Clock = std::chrono::high_resolution_clock;
  using TimePoint = std::chrono::time_point<Clock>;
  TimePoint start;
  TimePoint end;

  RuntimeMeasurement() { start = Clock::now(); }
  ~RuntimeMeasurement() { 
    end = Clock::now(); 
    auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time elapsed = " << time_elapsed.count() << '\n';
  }
};
