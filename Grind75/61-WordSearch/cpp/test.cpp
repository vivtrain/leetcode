#include "WordSearch.h"
#include "colors.h"
#include <prettyPrint.h>
#include <tuple>
#include <vector>
#include <string>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<tuple< vector<vector<char>>, string, bool >> testCases {
    { {{'A','B','C','E'},
       {'S','F','C','S'},
       {'A','D','E','E'}} , "ABCCED", true },
    { {{'A','B','C','E'},
       {'S','F','C','S'},
       {'A','D','E','E'}} , "ABCED", false },
    { {{'A','B','C','E'},
       {'S','F','C','S'},
       {'A','D','E','E'}} , "ABCCEDE", false },
  };

  for (auto &[board, word, answer] : testCases) {
    colorOut(LIGHT_BLUE, prettyString2D(board), ", ", word,
        " => ", boolalpha, answer) << endl;
    bool result = soln.exist(board, word);
    colorOut(result == answer ? GREEN : RED, boolalpha, result) << endl;
  }
}

