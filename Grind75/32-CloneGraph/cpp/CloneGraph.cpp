#include "CloneGraph.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;
typedef GraphNode Node;

Node* helper(Node *node, unordered_map<Node*, Node*>& cloned) {
  if (cloned.find(node) != cloned.end())
    return cloned[node];
  Node * clone = new Node(node->val);
  cloned[node] = clone;
  for (auto neighbor : node->neighbors)
    clone->neighbors.push_back(helper(neighbor, cloned));
  return cloned[node];
}
Node* CloneGraph::cloneGraph_recursive(Node* node) {
  if (!node) return nullptr;
  unordered_map<Node*, Node*> clones;
  return helper(node, clones);
}

Node* CloneGraph::cloneGraph(Node* node) {
  if (!node) return nullptr;

  Node *start = new Node(node->val);
  unordered_map<Node*, Node*> cloned;
  cloned[node] = start;

  queue<Node*> q;
  q.push(node);

  while (!q.empty()) {
    Node *node = q.front();
    q.pop();
    for (auto neighbor : node->neighbors) {
      if (cloned.find(neighbor) == cloned.end()) {
        cloned[neighbor] = new Node(neighbor->val);
        q.push(neighbor);
      }
      cloned[node]->neighbors.push_back(cloned[neighbor]);
    }
  }
  return start;
}

