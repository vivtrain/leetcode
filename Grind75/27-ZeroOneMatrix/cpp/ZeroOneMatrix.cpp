#include "ZeroOneMatrix.h"
#include <vector>
#include <queue>

using namespace std;

inline int min(const int &a, const int &b) {
  return (a < b) ? a : b;
}

vector<vector<int>> ZeroOneMatrix::updateMatrix(vector<vector<int>>& mat) {
  // Strategy: Multi-source BFS

  // Create a matrix of bools representing whether a cell has been visited
  int rows = mat.size(), cols = mat[0].size();
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));

  // Create a queue and prefill it with all the zeros in the matrix
  queue<pair<int, int>> coordQ;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (mat[r][c] == 0) {
        coordQ.push(make_pair(r,c));
        visited[r][c] = true;
      }
    }
  }

  // Perform BFS on the matrix, setting each value to 1 + min(neighbors)
  while (!coordQ.empty()) {
    pair<int, int> coord = coordQ.front();
    int r = coord.first, c = coord.second;
    coordQ.pop();
    // North
    if (r-1 >= 0 && !visited[r-1][c]) {
      mat[r-1][c] = mat[r][c] + 1;
      coordQ.push(make_pair(r-1,c));
      visited[r-1][c] = true;
    }
    // East
    if (c+1 < cols && !visited[r][c+1]) {
      mat[r][c+1] = mat[r][c] + 1;
      coordQ.push(make_pair(r,c+1));
      visited[r][c+1] = true;
    }
    // South
    if (r+1 < rows && !visited[r+1][c]) {
      mat[r+1][c] = mat[r][c] + 1;
      coordQ.push(make_pair(r+1,c));
      visited[r+1][c] = true;
    }
    // West
    if (c-1 >= 0 && !visited[r][c-1]) {
      mat[r][c-1] = mat[r][c] + 1;
      coordQ.push(make_pair(r,c-1));
      visited[r][c-1] = true;
    }
  }
  return mat;
}

