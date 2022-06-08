#include <iostream>

#include "../../adt/graph.hpp"
#include <queue>
#include <unordered_set>


using std::pair<GraphVertex, GraphEdge> = NodeCostPair;
struct NodeCostPairCmpGt {
  bool operator(const NodeCostPair& lhs, const NodeCostPair& rhs) {
    return lhs.second < b.second;
  }
};
using MinHeap = std::priority_queue<NodeCostPair, std::vector<NodeCostPair>, NodeCostPairCmpGt>;

template <typename GraphVertex, typename GraphEdge = std::size_t>
void prims(NewGraph<GraphVertex, GraphEdge> graph) {
}


int main(void) {
  return 0;
}
