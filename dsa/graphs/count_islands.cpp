#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>


struct Coordinate{
  int x;
  int y;
  Coordinate(): x(0), y(0) {}
  Coordinate(int x, int y): x(x), y(y) {}
  friend bool operator==(const Coordinate& lhs, const Coordinate& rhs) {
    return lhs.x == rhs.y && rhs.x == rhs.y;
  }
  friend bool operator<(const Coordinate& lhs, const Coordinate& rhs) {
    return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
  }
  friend Coordinate operator+(const Coordinate& lhs, const Coordinate& rhs) {
    return Coordinate(lhs.x + rhs.x, lhs.y + rhs.y);
  }
  enum Direction {
    RIGHT = 0,
    LEFT,
    DOWN,
    UP
  };
};


static const std::map<Coordinate::Direction, Coordinate> offsets = {
  { Coordinate::Direction::RIGHT, Coordinate(1, 0)  },
  { Coordinate::Direction::LEFT,  Coordinate(-1, 0) },
  { Coordinate::Direction::DOWN,  Coordinate(0, 1)  },
  { Coordinate::Direction::UP,    Coordinate(0, -1) }
};


inline bool is_within_landscape(const Coordinate& coordinate, std::size_t row_max, std::size_t col_max) {
  return (coordinate.x >= 0 && coordinate.x < row_max &&
          coordinate.y >= 0 && coordinate.y < col_max);
}

inline bool is_land(const Coordinate& coordinate, const std::vector<std::vector<int>>& landscape) {
  return (landscape[coordinate.x][coordinate.y] == 1);
}

void landscape_bfs(const std::vector<std::vector<int>>& landscape, const Coordinate& curr_coordinate, std::set<Coordinate>& visited_coordinates) {
  std::size_t row_max = landscape.size();
  std::size_t col_max = landscape[0].size();

  std::queue<Coordinate> coordinate_queue;
  coordinate_queue.push(curr_coordinate);
  visited_coordinates.insert(curr_coordinate);

  while(!coordinate_queue.empty()) {
    auto curr_coordinate = coordinate_queue.front();
    coordinate_queue.pop();
    
    for(auto offset: offsets) {
      auto next_coordinate = curr_coordinate + offset.second;
      if(is_within_landscape(next_coordinate, row_max, col_max) &&
         is_land(next_coordinate, landscape) &&
         visited_coordinates.find(next_coordinate) == visited_coordinates.end()) {
           coordinate_queue.push(next_coordinate);
           visited_coordinates.insert(next_coordinate);
      }
    }
  }
}

std::size_t number_of_islands(const std::vector<std::vector<int>>& landscape) {
  std::size_t row_max = landscape.size();
  std::size_t col_max = landscape[0].size();
  
  if(row_max == 0) return 0;
  
  std::set<Coordinate> visited_coordinates;
  std::size_t island_count = 0;

  for(std::size_t row_cnt = 0; row_cnt < row_max; row_cnt++) {
    for(std::size_t col_cnt = 0; col_cnt < col_max; col_cnt++) {
      Coordinate curr_coordinate(row_cnt, col_cnt);
      if(is_land(curr_coordinate, landscape) &&
         visited_coordinates.find(curr_coordinate) == visited_coordinates.end()) {
        island_count++;
        landscape_bfs(landscape, curr_coordinate, visited_coordinates);
      }
    }
  }

  return island_count;
}

int main(void) {
  std::vector<std::vector<int>> landscape_1 = {
    {1, 1, 1, 1, 0},
    {1, 1, 0, 1, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };
  std::cout << number_of_islands(landscape_1) << '\n';

  std::vector<std::vector<int>> landscape_2 = {
    {1, 1, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1}
  };
  std::cout << number_of_islands(landscape_2) << '\n';

  return 0;
}
