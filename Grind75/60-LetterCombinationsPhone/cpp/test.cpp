#include "LetterCombinationsPhone.h"
#include "colors.h"
#include <prettyPrint.h>
#include <utility>
#include <vector>
#include <string>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<pair<string, vector<string>>> testCases {
    { "", {} },
    { "2", {"a","b","c",} },
    { "22", {"aa","ab","ac","ba","bb","bc","ca","cb","cc",} },
    { "27", {"ap","bp","cp","aq","bq","cq","ar","br","cr","as","bs","cs",} },
  };

  for (const auto &[digits, answer] : testCases) {
    colorOut(LIGHT_BLUE, digits) << endl;
    colorOut(WHITE, prettyString(answer)) << endl;
    vector<string> result = soln.letterCombinations(digits);
    set<string> setAns(answer.begin(), answer.end());
    set<string> setRes(result.begin(), result.end());
    colorOut(setAns == setRes ? GREEN : RED, prettyString(result)) << endl;
  }
}

