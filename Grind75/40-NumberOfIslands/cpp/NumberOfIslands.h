#ifndef NUMBER_OF_ISLANDS
#define NUMBER_OF_ISLANDS

#include <vector>

class Solution {
  public:
    int numIslands(std::vector<std::vector<char>>& grid);
    int numIslands2(std::vector<std::vector<char>>& grid);
  private:
    const char LAND = '1';
    const char WATER = '0';
    const char VISITED = 'X';
    void markIsland(std::vector<std::vector<char>> &grid, int row, int col);
};

#endif

