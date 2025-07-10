#include "FindAllAnagramsOfString.h"
#include "colors.h"
#include <iomanip>
#include <prettyPrint.h>
#include <tuple>
#include <vector>
#include <string>

using namespace std;
using namespace colors;

int main() {
  Solution soln;
  vector<tuple< string, string, vector<int> >> testCases {
    { "abc", "ab", {0} },
    { "aba", "ab", {0,1} },
    { "bacbacb", "abc", {0,1,2,3,4} },
    { "bacdbacb", "abc", {0,4,5} },
  };
  
  for (auto &[s, p, answer] : testCases) {
    colorOut(LIGHT_BLUE, quoted(s), ", ", quoted(p));
    colorOut(LIGHT_BLUE, " => ", prettyString(answer)) << " --> ";
    vector<int> result = soln.findAnagrams(s, p);
    colorOut(result == answer ? GREEN : RED, prettyString(result)) << endl;
  }
}

