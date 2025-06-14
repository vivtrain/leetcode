#include "RottingOranges.h"
#include "colors.h"
#include <vector>
#include <prettyPrint.h>

using namespace std;

int main() {
  Solution soln;
  vector<pair<vector<vector<int>>, int>> testCases {
    { { {0} }, 0 },
    { { {1} }, -1 },
    { { {2} }, 0 },
    { { {1,1} }, -1 },
    { { {2,2} }, 0 },
    { { {2,1} }, 1 },
    { { {2,0,1} }, -1 },
    { { {2,1,1},{1,1,0},{0,1,1} }, 4 },
    { { {2,1,1},{1,1,1},{0,1,2} }, 2 },
    { { {2,1,1},{1,1,0},{0,0,1} }, -1 },
  };

  for (auto &test : testCases) {
    auto &[ grid, answer ] = test;
    prettyPrint2D(grid);
    cout << "Should take " << answer << " minutes to rot. Got ";
    int result = soln.orangesRotting(grid);
    if (result == answer)
      colorOut(colors::GREEN, result) << endl;
    else
      colorOut(colors::RED, result) << endl;
  }
}

