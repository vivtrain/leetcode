#include "RottingOranges.h"
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

inline constexpr bool oob(int r, int c, int nRows, int nCols) {
  return (r < 0 || r >= nRows || c < 0 || c >= nCols);
}

int Solution::orangesRotting(vector<vector<int>>& grid) {
  // Validate input
  if (grid.empty() || grid[0].empty())
    return -1;
  const int nRows = grid.size(), nCols = grid[0].size();

  // Generate start points for bfs (i.e. find initial rotten organes)
  queue<tuple<int, int, int>> rotPlaceTime;
  for (int r = 0; r < nRows; r++)
    for (int c = 0; c < nCols; c++)
      if (grid[r][c] == ROTTEN)
        rotPlaceTime.push(make_tuple(r, c, 0));

  // Run multi-start bfs to rot oranges
  int maxTime = 0;
  while (!rotPlaceTime.empty()) {
    auto [ r, c, elapsed ] = rotPlaceTime.front();
    rotPlaceTime.pop();
    maxTime = max(maxTime, elapsed);
    // cout << "visiting (" << r << ", " << c << ") at time " << e << endl;
    vector<pair<int, int>> directions { {r-1,c},{r,c+1},{r+1,c},{r,c-1} };
    for (auto [ row, col ] : directions) {
      if (!oob(row, col, nRows, nCols) && grid[row][col] == FRESH) {
        rotPlaceTime.push(make_tuple(row, col, elapsed+1));
        grid[row][col] = ROTTEN;
      }
    }
  }

  // Check that all organes are indeed rotten
  for (int r = 0; r < nRows; r++)
    for (int c = 0; c < nCols; c++)
      if (grid[r][c] == FRESH)
        return -1;

  return maxTime;
}

