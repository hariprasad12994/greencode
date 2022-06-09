#include <iostream>

#include "../../adt/graph.hpp"
#include <queue>
#include <unordered_set>
#include <cstdlib>


template <typename GraphVertex, typename GraphEdge = std::size_t>
std::size_t prims(NewGraph<GraphVertex, GraphEdge> graph) {
using NodeCostPair = std::pair<GraphVertex, GraphEdge>;
struct NodeCostPairCmpGt {
  bool operator()(const NodeCostPair& lhs, const NodeCostPair& rhs) {
    return lhs.second < rhs.second;
  }
};
using MinHeap = std::priority_queue<NodeCostPair, std::vector<NodeCostPair>, NodeCostPairCmpGt>;
  MinHeap pq;
  std::unordered_set<GraphVertex> visited_nodes;
  std::size_t cost = 0;

  pq.push(NodeCostPair(graph.begin().first, 0));
  visited_nodes.insert(graph.begin().first);

  while(!pq.empty()) {
    auto current_node = pq.top();
    pq.pop();
    cost = cost + current_node.edge;
    for(auto next_node: graph[current_node]) {
      if(visited_nodes.find(next_node) == visited_nodes.end()) {
	pq.push(NodeCostPair(next_node.vertex, next_node.edge));
	visited_nodes.insert(next_node.vertex);
      }
    }
  }
  return cost;
};


int main(void) {
  NewGraph<std::size_t, std::size_t> this_graph;
  std::vector<std::pair<std::size_t, std::size_t>> points = {
    {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}
  };
  for(std::size_t outer = 0; outer < points.size(); outer++) {
    for(std::size_t inner = outer + 1; inner < points.size(); inner++) {
      auto distance = std::abs(points[outer].first - points[inner].first) + std::abs(points[outer].second - points[inner].second);
      this_graph.add_edge(outer, inner, distance);
    }
  }
  std::cout << prims(this_graph) << '\n';
  return 0;
}
