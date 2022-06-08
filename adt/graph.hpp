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

  AdjacencyList graph;

  void add_node(GraphNode id) {
    if(graph.find(id) == graph.end()) {
      graph[id] = AdjacencyListEntry();
    }
  }
  
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


template <typename GraphVertex, typename GraphEdge = std::size_t>
class NewGraph {
  public:
    struct GraphNode {
      public:
        GraphVertex vertex;
        GraphEdge edge;
        GraphNode() = delete;
        GraphNode(GraphVertex vertex, GraphEdge edge): vertex(vertex), edge(edge) {}
    };
    using AdjacencyListEntry = std::vector<GraphNode>;
    using AdjacencyList = std::unordered_map<GraphVertex, AdjacencyListEntry>;

    NewGraph() = default;
    ~NewGraph() = default;

    void add_node(GraphVertex id) {
      if(graph.find(id) == graph.end()) {
        graph[id] = AdjacencyListEntry();
      }
    }
    
    void add_edge(GraphVertex source, GraphVertex dest, GraphEdge weight=0) {
      add_node(source);
      add_node(dest);
      graph[source].emplace_back(GraphNode(dest, weight));
    }

    void add_bidirectional_edge(GraphVertex source, GraphVertex dest, GraphEdge weight=0) {
      add_node(source);
      add_node(dest);
      graph[source].emplace_back(GraphNode(dest, weight));
      graph[dest].emplace_back(GraphNode(source, weight));
    }

    AdjacencyListEntry& operator[](GraphVertex vertex) {
      return graph[vertex];
    }
  
  private:
    AdjacencyList graph;
};
