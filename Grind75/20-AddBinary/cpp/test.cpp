#include "AddBinary.h"
#include <cstdio>
#include <cassert>
#include <vector>
#include <tuple>

int main() {
  using namespace std;
  AddBinary soln;
  vector<tuple<string, string, string>> testCases {
    {"", "", "0"},
    {"0", "", "0"},
    {"", "0", "0"},
    {"0", "0", "0"},
    {"1", "0", "1"},
    {"0", "1", "1"},
    {"1", "1", "10"},
    {"1", "10", "11"},
    {"10", "1", "11"},
    {"10", "11", "101"},
    {"11", "11", "110"},
    {"1010", "1011", "10101"},
  };

  for (auto test : testCases) {
    const char *a = get<0>(test).c_str();
    const char *b = get<1>(test).c_str();
    const char *s = get<2>(test).c_str();
    printf("\"%s\" + \"%s\" == \"%s\" -> ", a, b, s);
    std::string result = soln.addBinary(a, b);
    printf("\"%s\"\n", result.c_str());
    assert(result == s);
  }
  printf("TESTS PASSED!\n");
}

