#include "SpiralMatrix.h"
#include <vector>
#include <climits>

using namespace std;

inline bool visitable(
    const size_t &r,
    const size_t &c,
    const vector<vector<int>> &matrix) {
  return
    0 <= r && r < matrix.size()
    && 0 <= c && c < matrix[0].size()
    && matrix[r][c] != INT_MIN;
}

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
  if (matrix.empty() || matrix[0].empty())
    return {};
  vector<int> spiralOrdered;

  size_t r = 0, c = 0;
  while (true) {
    spiralOrdered.push_back(matrix[r][c]);
    matrix[r][c] = INT_MIN;
    bool rightVisitable = visitable(r,   c+1, matrix);
    bool downVisitibale = visitable(r+1, c,   matrix);
    bool leftVisitable  = visitable(r,   c-1, matrix);
    bool upVisitable    = visitable(r-1, c,   matrix);

    if      (rightVisitable && !upVisitable)    c++;
    else if (downVisitibale && !rightVisitable) r++;
    else if (leftVisitable  && !downVisitibale) c--;
    else if (upVisitable    && !leftVisitable)  r--;
    else break;
    
  }

  return spiralOrdered;
}

