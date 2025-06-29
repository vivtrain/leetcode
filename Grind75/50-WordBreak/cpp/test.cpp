#include "WordBreak.h"
#include "colors.h"
#include <string>
#include <tuple>
#include <vector>
#include <prettyPrint.h>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<tuple<string, vector<string>, bool>> testCases {
    { "a", {"a"}, true },
    { "ab", {"a","b"}, true },
    { "ab", {"ab"}, true },
    { "aaa", {"aa", "a"}, true },
    { "aaaaaaa", {"aaaa", "aaa"}, true },
    { "aaaaaaa", {"aaaa"}, false },
    { "catsanddog", {"cat", "cats", "and", "sand", "dog"}, true },
    { "catsandog", {"cat", "cats", "and", "sand", "dog"}, false },
  };

  for (auto &[s, wordDict, answer] : testCases) {
    colorOut(LIGHT_BLUE, s, ", ", prettyString(wordDict), " => ", boolalpha, answer, " ");
    bool result = soln.wordBreak(s, wordDict);
    cout << "--> ";
    colorOut(result == answer ? GREEN : RED, result) << endl;
  }
}

