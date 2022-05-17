#include <iostream>
#include "../lib/graph.hpp"
#include <unordered_set>
#include <set>
#include <stack>


void depth_first_search(Graph<int>& g, int start_node) {
  std::stack<int> traversal_stack;
  std::unordered_set<int> visited_nodes;

  traversal_stack.push(start_node);

  while(!traversal_stack.empty()) {
    auto current_node = traversal_stack.top();
    std::cout << current_node << " ";
    visited_nodes.insert(current_node);
    traversal_stack.pop();
    for(auto& node_entry: g.graph[current_node]) {
      if(visited_nodes.find(node_entry.dest) == visited_nodes.end()) {
        traversal_stack.push(node_entry.dest);
      }
    }
  }
  std::cout << '\n';
}


void top_sort(const Graph<int>& g) {
  
}


int main(void) {
  Graph<int> this_graph;
  this_graph.add_edge(0, 1);
  this_graph.add_edge(0, 2);
  this_graph.add_edge(1, 2);
  this_graph.add_edge(2, 0);
  this_graph.add_edge(2, 3);
  this_graph.add_edge(3, 3);
  depth_first_search(this_graph, 1);

  Graph<int> another_graph;
  another_graph.add_edge(2, 0);
  another_graph.add_edge(0, 2);
  another_graph.add_edge(1, 2);
  another_graph.add_edge(0, 1);
  another_graph.add_edge(3, 3);
  another_graph.add_edge(1, 3);
  depth_first_search(another_graph, 2);

  return 0;
}
