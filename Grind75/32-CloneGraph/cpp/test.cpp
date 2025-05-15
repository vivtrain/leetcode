#include "CloneGraph.h"
#include <iostream>
#include <cassert>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main() {
  CloneGraph soln;
  vector<GraphNode> nodes(5);
  
  for (int i = 0; static_cast<size_t>(i) < nodes.size(); i++) {
    nodes[i].val = i+1;
  }
  nodes[0].neighbors.push_back(&nodes[1]);
  nodes[0].neighbors.push_back(&nodes[3]);

  nodes[1].neighbors.push_back(&nodes[0]);
  nodes[1].neighbors.push_back(&nodes[2]);

  nodes[2].neighbors.push_back(&nodes[1]);
  nodes[2].neighbors.push_back(&nodes[3]);

  nodes[3].neighbors.push_back(&nodes[0]);
  nodes[3].neighbors.push_back(&nodes[2]);
  
  GraphNode *newGraph = soln.cloneGraph(&nodes[0]);
  queue<GraphNode*> q;
  unordered_set<GraphNode*> visited;
  q.push(newGraph);
  while (!q.empty()) {
    GraphNode *n = q.front();
    q.pop();
    if (visited.find(n) != visited.end())
      continue;
    visited.insert(n);
    cout << "cloned " << n->val;
    cout << " whose neighbors are [ ";
    for (auto neighbor : n->neighbors) {
      cout << neighbor->val << " ";
      if (visited.find(neighbor) == visited.end())
        q.push(neighbor);
    }
    cout << "]" << endl;
  }
}

