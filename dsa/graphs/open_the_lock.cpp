#include <queue>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <utility>

const std::string inc_map[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
const std::string dec_map[10] = {"9", "8", "7", "6", "5", "4", "3", "2", "1", "0"};

int open_the_lock(const std::unordered_set<std::string> dead_ends, const std::string& target) {
  std::unordered_set<std::string> visited_lock_states;
  std::queue<std::pair<std::string, std::size_t>> state_queue;

  state_queue.push(std::make_pair<std::string, std::size_t>("0000", 0));
  visited_lock_states.insert("0000");

  std::size_t move_count = 0;

  while(!state_queue.empty()) {
    if(state_queue.front().first == target) {
      return state_queue.front().second;
    }
    
    std::string current_wheels_state = state_queue.front().first;
    std::size_t move_count = state_queue.front().second + 1;
    state_queue.pop();

    for(std::size_t pos = 0; pos < target.size(); pos++) {
      auto next_state_clockwise = current_wheels_state;
      next_state_clockwise.replace(pos, 1, inc_map[next_state_clockwise[pos] - '0']);
      if(visited_lock_states.find(next_state_clockwise) == visited_lock_states.end() && dead_ends.find(next_state_clockwise) == dead_ends.end()) {
        state_queue.push(std::make_pair(next_state_clockwise, move_count));
        visited_lock_states.insert(next_state_clockwise);
      }

      auto next_state_anticlockwise = current_wheels_state;
      next_state_anticlockwise.replace(pos, 1, dec_map[next_state_anticlockwise[pos] - '0']);
      if(visited_lock_states.find(next_state_anticlockwise) == visited_lock_states.end() && dead_ends.find(next_state_anticlockwise) == dead_ends.end()) {
        state_queue.push(std::make_pair(next_state_anticlockwise, move_count));
        visited_lock_states.insert(next_state_anticlockwise);
      }
    }
  }
  
  return -1;
}

int main(void) {
  std::cout << open_the_lock(std::unordered_set<std::string>{"0201", "0101", "0102", "1212", "2002"}, std::string("0202")) << '\n';
  std::cout << open_the_lock(std::unordered_set<std::string>{"8888"}, std::string("0009")) << '\n';
  std::cout << open_the_lock(std::unordered_set<std::string>{"8887", "8878", "8898", "8788", "8988", "7888", "9888"}, std::string("8888")) << '\n';
  std::cout << open_the_lock(std::unordered_set<std::string>{"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"}, std::string("8888")) << '\n';
  return 0;
}
