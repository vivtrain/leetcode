#include "WordLadder.h"
#include <prettyPrint.h>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<tuple<string, string, vector<string>, int>> testCases {
    { "hit", "cog", {"hot","dot","dog","lot","log","cog"}, 5 },
  };

  for (auto &[begin, end, list, answer] : testCases) {
    cout << soln.ladderLength(begin, end, list) << endl;
  }
}


