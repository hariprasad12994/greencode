
#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>
#include <limits>
#include "../../adt/graph.hpp"


void djikstras(NewGraph<std::size_t, std::size_t> graph, GraphVertex start_node) {
  using GraphNode = NewGraph<std::size_t, std::size_t>::GraphNode;
  std::priority_queue<GraphNode, std::vector<GraphNode>, std::greater<GraphNode>> node_queue;
  std::map<GraphVertex, GraphEdge> distances;
  std::unordered_set<GraphVertex> visited_nodes;
  
  node_queue.push(GraphNode(start_node, 0));
  distances[start_node] = 0;

  while(!node_queue.empty()) {
    auto current_node = node_queue.top();
    node_queue.pop();
    visited_nodes.insert(current_node.dest);

    for(auto& edge: graph.graph[current_node.dest]) {
      auto distance = edge.weight + current_node.weight;
      if(distances.find(edge.dest) == distances.end())
        distances[edge.dest] = std::numeric_limits<uint64_t>::max();
      if(distances[edge.dest] > distance)
        distances[edge.dest] = distance;
      if(visited_nodes.find(edge.dest) == visited_nodes.end()) {
        node_queue.push(GraphEdge(edge.dest, distance));
      }
    }
  }

  for(auto entry: distances) {
    std::cout << entry.first << " --> " << entry.second << '\n';
  }
}


int main(void) {
  NewGraph<std::size_t, std::size_t> this_graph;

  this_graph.add_edge(0, 1, 2);
  this_graph.add_edge(0, 2, 6);
  this_graph.add_edge(1, 3, 5);
  this_graph.add_edge(2, 3, 8);
  this_graph.add_edge(3, 5, 15);
  this_graph.add_edge(3, 4, 10);
  this_graph.add_edge(5, 6, 6);
  this_graph.add_edge(4, 6, 2);
  this_graph.add_edge(4, 5, 6);

  return 0;
}
