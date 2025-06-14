#ifndef ROTTING_ORANGES
#define ROTTING_ORANGES

#include <vector>

class Solution {
  public:
    int orangesRotting(std::vector<std::vector<int>>& grid);
  private:
    const int EMPTY = 0;
    const int FRESH = 1;
    const int ROTTEN = 2;
};


#endif

