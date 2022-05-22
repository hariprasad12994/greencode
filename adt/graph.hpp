#include <unordered_map>
#include <vector>
#include <iostream>


template <typename T>
struct Graph {
public:
  using GraphNode = T;
  using Weight = std::size_t;
  
  struct GraphEdge {
    T dest;
    Weight weight;
    GraphEdge(T dst, Weight wt): dest(dst), weight(wt) {}
    friend bool operator<(const GraphEdge& lhs, const GraphEdge& rhs) {
      return lhs.weight < rhs.weight;
    }
    friend bool operator>(const GraphEdge& lhs, const GraphEdge& rhs) {
      return lhs.weight > rhs.weight;
    }
  };
  using AdjacencyListEntry = std::vector<GraphEdge>;
  using AdjacencyList = std::unordered_map<GraphNode, AdjacencyListEntry>;
  
  // todo : rename to adjacency_list
  AdjacencyList graph;

  void add_node(GraphNode id) {
    if(graph.find(id) == graph.end()) {
      graph[id] = AdjacencyListEntry();
    }
  }
  
  // todo : handle 1. directed, 2. unweighted graphs
  void add_edge(GraphNode source, GraphNode dest, Weight weight=0) {
    add_node(source);
    add_node(dest);
    graph[source].emplace_back(dest, weight);
  }

  void add_bidirectional_edge(GraphNode source, GraphNode dest, Weight weight=0) {
    add_node(source);
    add_node(dest);
    graph[source].emplace_back(dest, weight);
    graph[dest].emplace_back(source, weight);
  }
};
