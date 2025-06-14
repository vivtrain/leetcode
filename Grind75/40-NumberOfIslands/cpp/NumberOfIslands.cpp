#include "NumberOfIslands.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int Solution::numIslands(vector<vector<char>>& grid) {
  if (grid.empty() || grid[0].empty())
    return 0;
  const int nRows = grid.size();
  const int nCols = grid[0].size();
  // cout << nRows << " rows, " << nCols << " cols " << endl;

  vector<vector<bool>> visited(nRows, vector<bool>(nCols, false));
  queue<pair<int,int>> coordStack;
  int islandCount = 0;

  for (int r = 0; r < nRows; r++) {
    for (int c = 0; c < nCols; c++) {
      // for every cell, start a DFS
      if (visited[r][c])
        continue;
      coordStack.push(make_pair(r,c));
      // cout << "start dfs from (" << r << "," << c << ")" << endl;
      bool visitingIsland = false;
      while (!coordStack.empty()) {
        const pair<int,int> cur = coordStack.front();
        const int curRow = cur.first, curCol = cur.second;
        coordStack.pop();
        if (visited[curRow][curCol])
          continue;
        // cout << "visit (" << curRow << "," << curCol << ")" << endl;
        visited[curRow][curCol] = true;
        if (grid[curRow][curCol] == WATER)
          continue;
        else if (grid[curRow][curCol] == LAND && !visitingIsland) {
          visitingIsland = true;
          islandCount++;
        }
        if (curRow - 1 >= 0) // North
          coordStack.push(make_pair(curRow-1, curCol));
        if (curCol + 1 < nCols) // East
          coordStack.push(make_pair(curRow, curCol+1));
        if (curRow + 1 < nRows) // South
          coordStack.push(make_pair(curRow+1, curCol));
        if (curCol - 1 >= 0) // West
          coordStack.push(make_pair(curRow, curCol-1));
      }
    }
  }

  return islandCount;
}

void Solution::markIsland(vector<vector<char>> &grid, int row, int col) {
  const int nRows = grid.size();
  const int nCols = grid[0].size();
  if (row < 0 || row >= nRows || col < 0 || col >= nCols)
    return;
  if (grid[row][col] == VISITED || grid[row][col] == WATER)
    return;
  grid[row][col] = VISITED;
  markIsland(grid, row-1, col  );
  markIsland(grid, row,   col+1);
  markIsland(grid, row+1, col  );
  markIsland(grid, row,   col-1);
}

int Solution::numIslands2(vector<vector<char>>& grid) {
  if (grid.empty() || grid[0].empty())
    return 0;
  const int nRows = grid.size();
  const int nCols = grid[0].size();
  int islandCount = 0;

  for (int r = 0; r < nRows; r++) {
    for (int c = 0; c < nCols; c++) {
      // for every cell, start a DFS
      if (grid[r][c] == WATER || grid[r][c] == VISITED)
        continue;
      islandCount++;
      markIsland(grid, r, c); 
    }
  }

  return islandCount;
}

