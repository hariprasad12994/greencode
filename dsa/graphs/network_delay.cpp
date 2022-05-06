#include "../lib/graph.hpp"
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <unordered_set>
#include <utility>


std::size_t mst_cost(Graph<int>& g, int start_node) {
  using MinHeap = std::priority_queue<Graph<int>::GraphEdge, 
                                      std::vector<Graph<int>::GraphEdge>, 
                                      std::greater<Graph<int>::GraphEdge>>;
  using Set = std::unordered_set<int>;
  MinHeap heap;
  Set visited_nodes;

  heap.push(Graph<int>::GraphEdge(start_node, 0));

  std::size_t cost = 0;
  while(visited_nodes.size() < g.graph.size()) {
    auto visited_node = heap.top();
    heap.pop();
    if(visited_nodes.find(visited_node.dest) == visited_nodes.end()) {
      visited_nodes.insert(visited_node.dest);
      cost = std::max(cost, visited_node.weight);
      for(auto& node: g.graph[visited_node.dest]) {
        heap.push(Graph<int>::GraphEdge(node.dest, visited_node.weight + node.weight));
      }
    }
  }
  
  return cost;
}


int main(void) {
  Graph<int> graph_1;
  std::vector<std::tuple<int, int, int>> points = {
    {2, 1, 1}, {2, 3, 1}, {3, 4, 1}
  };
  for(auto const& point: points) {
    graph_1.add_edge(std::get<0>(point), std::get<1>(point), std::get<2>(point));
  }
  //std::cout << mst_cost(graph_1, 0) << '\n';
  //std::cout << mst_cost(graph_1, 4) << '\n';
  std::cout << mst_cost(graph_1, 2) << '\n';

  return 0;
}
