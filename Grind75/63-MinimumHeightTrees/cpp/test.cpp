#include "MinimumHeightTrees.h"
#include <prettyPrint.h>
#include <vector>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<vector<int>> edges {{1,0},{1,2},{1,3}};
  soln.findMinHeightTrees(4, edges);
}

