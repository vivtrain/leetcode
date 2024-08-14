#include "RansomNote.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <tuple>

int main() {
  using namespace std;
  vector<tuple<string, string, bool>> testCases(
    {
      {"", "", true},
      {"a", "a", true},
      {"a", "aa", true},
      {"aa", "a", false},
      {"ab", "aa", false},
      {"abc", "abbccc", true},
      {"abbc", "abbccc", true},
      {"abbccc", "abbccc", true},
      {"abbcccc", "abbccc", false},
      {"abbbccc", "abbccc", false},
      {"aabbccc", "abbccc", false},
    });
  RansomNote soln;

  for (tuple<string, string, bool> test : testCases) {
    cout <<
        "\"" << get<0>(test).c_str() << "\", " <<
        "\"" << get<1>(test).c_str() << "\", " << boolalpha <<
        get<2>(test) << " -> " << flush;
    bool result = soln.canConstruct3(get<0>(test), get<1>(test));
    cout << boolalpha << result << endl;
    assert(result == get<2>(test));
  }
}

