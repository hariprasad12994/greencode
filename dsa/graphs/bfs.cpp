#include <iostream>

#include <unordered_set>
#include <queue>
#include "../../adt/graph.hpp"


template <typename GraphVertex, typename GraphEdge>
void bfs(NewGraph<GraphVertex, GraphEdge> graph, GraphVertex start_node) {
  std::queue<GraphVertex> traversal_queue;
  std::unordered_set<GraphVertex> visited_nodes;
  
  traversal_queue.push(start_node);
  visited_nodes.insert(start_node);

  while(!traversal_queue.empty()) {
    auto current_node = traversal_queue.front();
    traversal_queue.pop();
    std::cout << current_node << " ";
    for(auto node: graph[current_node]) {
      if(visited_nodes.find(node.vertex) == visited_nodes.end()) {
        traversal_queue.push(node.vertex);
        visited_nodes.insert(node.vertex);
      }
    }
  }
  std::cout << '\n';
}


int main(void) {
  NewGraph<std::size_t, std::size_t> this_graph;
  this_graph.add_bidirectional_edge(0, 9);
  this_graph.add_bidirectional_edge(0, 1);
  this_graph.add_bidirectional_edge(1, 8);
  this_graph.add_bidirectional_edge(9, 8);
  this_graph.add_bidirectional_edge(8, 7);
  this_graph.add_bidirectional_edge(7, 10);
  this_graph.add_bidirectional_edge(10, 11);
  this_graph.add_bidirectional_edge(7, 11);
  this_graph.add_bidirectional_edge(7, 3);
  this_graph.add_bidirectional_edge(7, 6);
  this_graph.add_bidirectional_edge(3, 2);
  this_graph.add_bidirectional_edge(3, 4);
  this_graph.add_bidirectional_edge(3, 5);
  this_graph.add_bidirectional_edge(6, 5);
  bfs(this_graph, static_cast<std::size_t>(0));

  return 0;
}
