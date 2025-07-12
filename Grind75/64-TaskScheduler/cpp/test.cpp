#include "TaskScheduler.h"
#include "colors.h"
#include <prettyPrint.h>
#include <tuple>
#include <vector>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<tuple<vector<char>, int, int>> testCases {
    { {'A'}, 2, 1},
    { {'A','A'}, 2, 4 },
    { {'A','A','B','C'}, 2, 4 },
    { {'B','C','D','A','A','A','A','G'}, 1, 8 },
    { {'A','A','A','B','B','B',}, 2, 8 },
    { {'A','B','C','D','E','A','B','C','D','E'}, 4, 10 },
  };
  for (auto &[tasks, n, answer] : testCases) {
    colorOut(LIGHT_BLUE, prettyString(tasks), ", ", n, " => ", answer);
    int result = soln.leastInterval(tasks, n);
    cout << " --> ";
    colorOut(result == answer ? GREEN : RED, result) << endl;
  }
}

