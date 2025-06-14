#include "NumberOfIslands.h"
#include "colors.h"
#include <iostream>
#include <vector>
#include <prettyPrint.h>

using namespace std;

int main() {
  Solution soln;
  vector< pair< vector<vector<char>>, int > > testCases = {
    {
      {
        { '1','1','1','1','0' },
        { '1','1','0','1','0' },
        { '1','1','0','0','0' },
        { '0','0','0','0','0' }
      }, 1
    },
    {
      {
        { '1','1','0','0','0' },
        { '1','1','0','0','0' },
        { '0','0','1','0','0' },
        { '0','0','0','1','1' }
      }, 3
    },
  };

  for (pair< vector<vector<char>>, int > &test : testCases) {
    auto& [grid, answer] = test;
    prettyPrint2D(grid);
    cout << "should have " << answer << " islands. Got ";
    int result = soln.numIslands2(grid);
    (result == answer) ? colorOut(colors::GREEN, result) : colorOut(colors::RED, result);
    cout << endl;
  }
}

