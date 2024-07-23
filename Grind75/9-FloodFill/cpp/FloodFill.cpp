#include "FloodFill.h"
#include <queue>
#include <tuple>

std::vector<std::vector<int>> FloodFill::floodFill(
    std::vector<std::vector<int>>& image,
    int sr,
    int sc,
    int color) {

  int m = image.size();
  int n = (image.empty()) ? 0 : image[0].size();

  if (sr < 0 || sr >= m)
    return image;
  if (sc < 0 || sc >= n)
    return image;

  int origColor = image[sr][sc];
  std::queue<std::pair<int, int>> q;
  q.push(std::make_pair(sr, sc));

  while (!q.empty()) {
    std::pair<int, int> coord = q.front();
    int row = coord.first;
    int col = coord.second;
    image[row][col] = color;
    q.pop();
    if (row-1 >= 0 && image[row-1][col] == origColor)
      q.push(std::make_pair(row-1, col));
    if (row+1 < m && image[row+1][col] == origColor)
      q.push(std::make_pair(row+1, col));
    if (col-1 >= 0 && image[row][col-1] == origColor)
      q.push(std::make_pair(row, col-1));
    if (col+1 < n && image[row][col+1] == origColor)
      q.push(std::make_pair(row, col+1));
  }
  return image;
}

