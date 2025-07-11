#include "MinimumHeightTrees.h"
#include "prettyPrint.h"

using namespace std;

void longestPath(const int root, const vector<vector<int>> &adj,
    vector<int> &path, vector<int> &longest) {
  // cout << "root: " << root << endl;
  path.push_back(root);
  bool noNeighbors = true;
  for (const int &nbr : adj[root]) {
    if (path.size() > 1 && nbr == path[path.size()-2])
      continue;
    longestPath(nbr, adj, path, longest);
    noNeighbors = false;
    // cout << "nbr: " << nbr << ", path: " << prettyString(nbrPath) << endl;
  }
  if ( (noNeighbors && longest.empty())
      || (!longest.empty() && path.size() > longest.size()) )
    longest = path;
  path.pop_back();
}

vector<int> Solution::findMinHeightTrees(int n, vector<vector<int>>& edges) {
  // Build adjacency list
  vector<vector<int>> adj(n);
  for (const vector<int> &edge : edges) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }

  vector<int> path, pathFrom0, pathFromFurthest;
  longestPath(0, adj, path, pathFrom0);
  longestPath(pathFrom0.back(), adj, path, pathFromFurthest);
  prettyPrint(pathFromFurthest);
  int N = pathFromFurthest.size();
  if (pathFromFurthest.size() % 2 == 0)
    return { pathFromFurthest[(N-1)/2], pathFromFurthest[(N-1)/2 + 1] };
  else
    return { pathFromFurthest[(N-1)/2] };
}

