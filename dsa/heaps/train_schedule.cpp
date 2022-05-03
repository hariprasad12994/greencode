#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>


struct TrainTime {
public:
  int arrival_time;
  int departure_time;
  TrainTime(int arrival_time_, int departure_time_): arrival_time(arrival_time_), departure_time(departure_time_) {}
  friend bool operator<(const TrainTime& lhs, const TrainTime& rhs) {
    return lhs.arrival_time > rhs.arrival_time;
  }
};

int minimum_platforms(const std::vector<int>& arrival_times, const std::vector<int>& departure_times) {
  std::vector<TrainTime> train_time_list;

  std::transform(arrival_times.begin(), arrival_times.end(), departure_times.begin(), std::back_inserter(train_time_list), 
                 [](auto arrival_time, auto departure_time) { return TrainTime(arrival_time, departure_time); });

  std::priority_queue<TrainTime, std::vector<TrainTime>> schedule_table(train_time_list.begin(), train_time_list.end());

  //while(!schedule_table.empty()) 
    //std::cout << schedule_table.top().arrival_time << "," << schedule_table.top().departure_time << '\n';
    //schedule_table.pop();
  //}

  auto platform_cnt = 1;
  auto first_train = schedule_table.top();
  schedule_table.pop();
  while(!schedule_table.empty()) {
    if(first_train.departure_time >= schedule_table.top().arrival_time)
      platform_cnt++;
    first_train = schedule_table.top();
    schedule_table.pop();
  }
  
  return platform_cnt;
}

int main(void) {
  std::cout << minimum_platforms(std::vector<int>{900, 940, 950, 1100, 1500, 1800}, std::vector<int>{910, 1200, 1120, 1130, 1900, 2000}) << '\n';
  std::cout << minimum_platforms(std::vector<int>{900, 940}, std::vector<int>{910, 1200}) << '\n';
  return 0;
}
