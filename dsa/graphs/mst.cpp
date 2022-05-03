#include "graph.hpp"
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <unordered_set>


int mst_cost(Graph<int>& g, int start_node) {
  using MinHeap = std::priority_queue<Graph<int>::GraphEdge, 
                                      std::vector<Graph<int>::GraphEdge>, 
                                      std::greater<Graph<int>::GraphEdge>>;
  using Set = std::unordered_set<int>;
  MinHeap heap;
  Set visited_nodes;

  heap.push(Graph<int>::GraphEdge(start_node, 0));

  int cost = 0;
  while(visited_nodes.size() < g.graph.size()) {
    auto visited_node = heap.top();
    heap.pop();
    if(visited_nodes.find(visited_node.dest) == visited_nodes.end()) {
      visited_nodes.insert(visited_node.dest);
      cost = cost + visited_node.weight;
      for(auto& node: g.graph[visited_node.dest]) {
        heap.push(node);
      }
    }
  }
  
  return cost;
}


int main(void) {
  Graph<int> graph_1;
  std::vector<std::pair<int, int>> points = {
    {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}
  };
  for(std::size_t outer = 0; outer < points.size(); outer++) {
    for(std::size_t inner = outer + 1; inner < points.size(); inner++) {
      auto distance = std::abs(points[outer].first - points[inner].first) + std::abs(points[outer].second - points[inner].second);
      graph_1.add_edge(outer, inner, distance);
    }
  }
  std::cout << mst_cost(graph_1, 0) << '\n';
  std::cout << mst_cost(graph_1, 4) << '\n';
  std::cout << mst_cost(graph_1, 2) << '\n';

  return 0;
}
