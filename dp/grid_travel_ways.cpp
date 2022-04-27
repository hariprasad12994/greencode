#include <iostream>
#include "../runtime.hpp"
#include <map>
#include <vector>

struct Point {
public:
  int x;
  int y;
  Point(): x(0), y(0) {}
  Point(int x_, int y_): x(x_), y(y_) {}

  friend bool operator==(const Point& lhs, const Point& rhs) { return lhs.x == rhs.x && lhs.y == lhs.y; }
  friend bool operator!=(const Point& lhs, const Point& rhs) { return !(lhs == rhs); }
  friend bool operator<(const Point& lhs, const Point& rhs) { return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y); }
};

unsigned int grid_travel_memo(int src_x, int src_y, int dest_x, int dest_y, std::map<Point, int>& memo) {
  Point pt(dest_x, dest_y);
  if(memo.find(pt) != memo.end()) return memo[pt];
  if(dest_x == src_x && dest_y == src_y) return 1;
  if(dest_x == 0 || dest_y == 0) return 0;

  memo[pt] = grid_travel_memo(src_x, src_y, dest_x - 1, dest_y, memo) +
                                grid_travel_memo(src_x, src_y, dest_x, dest_y - 1, memo);
  return memo[pt];
}

unsigned int grid_travel_memo(int src_x, int src_y, int dest_x, int dest_y) {
  std::map<Point, int> memo;
  return grid_travel_memo(src_x, src_y, dest_x, dest_y, memo);
}

unsigned int grid_travel(int src_x, int src_y, int dest_x, int dest_y) {
  if(dest_x == src_x && dest_y == src_y) return 1;
  if(dest_x == 0 || dest_y == 0) return 0;

  return grid_travel(src_x, src_y, dest_x - 1, dest_y) +
         grid_travel(src_x, src_y, dest_x, dest_y - 1);
}

struct TestInput{
public:
  Point src;
  Point dest;
  TestInput(Point a_, Point b_): src(a_), dest(b_) {}
};

int main(void) {
  std::vector<TestInput> inputs = {
    {Point(1, 1), Point(3, 3)},
    {Point(3, 3), Point(1, 1)},
    {Point(1, 0), Point(1, 0)},
    {Point(3, 3), Point(4, 8)},
    //{Point(4, 4), Point(10, 8)},
    //{Point(10,8), Point(4, 4)},
    //{Point(4, 4), Point(20, 20)},
    //{Point(4, 4), Point(50, 50)},
    //{Point(4, 4), Point(100, 100)}
  };

  std::cout << "Brute Force" << '\n';
  for(auto input: inputs) {
    {
      RuntimeMeasurement rm;
      std::cout << "Input = " << "Src (" << input.src.x << ", " << input.src.y << "); " << "Dest (" << input.dest.x << ", " << input.dest.y << ");"
                << " Output = " << grid_travel(input.src.x, input.src.y, input.dest.x, input.dest.y) << '\n';
    }
  }
  std::cout << '\n';

  std::vector<TestInput> memo_inputs = {
    {Point(1, 1), Point(3, 3)},
    {Point(3, 3), Point(1, 1)},
    {Point(1, 0), Point(1, 0)},
    {Point(3, 3), Point(4, 8)},
    {Point(4, 4), Point(10, 8)},
    {Point(10,8), Point(4, 4)},
    {Point(4, 4), Point(20, 20)},
    {Point(4, 4), Point(50, 50)},
    {Point(4, 4), Point(100, 100)},
    {Point(1, 1), Point(18, 18)}
  };
  std::cout << "Memo" << '\n';
  for(auto input: memo_inputs) {
    {
      RuntimeMeasurement rm;
      std::cout << "Input = " << "Src (" << input.src.x << ", " << input.src.y << "); " << "Dest (" << input.dest.x << ", " << input.dest.y << ");"
                << " Output = " << grid_travel_memo(input.src.x, input.src.y, input.dest.x, input.dest.y) << '\n';
    }
  }
  std::cout << '\n';

  return 0;
}

