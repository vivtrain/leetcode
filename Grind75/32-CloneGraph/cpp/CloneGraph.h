#ifndef CLONE_GRAPH
#define CLONE_GRAPH

#include <vector>

class GraphNode {
public:
  int val;
  std::vector<GraphNode*> neighbors;
  GraphNode() {
    val = 0;
    neighbors = std::vector<GraphNode*>();
  }
  GraphNode(int value) {
    val = value;
    neighbors = std::vector<GraphNode*>();
  }
  GraphNode(int value, std::vector<GraphNode*> _neighbors) {
    val = value;
    neighbors = _neighbors;
  }
};

class CloneGraph {
  public:
    GraphNode* cloneGraph_recursive(GraphNode* node);
    GraphNode* cloneGraph(GraphNode* node);
  private:
};

#endif

