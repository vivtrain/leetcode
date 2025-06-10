#include "ProductExceptSelf.h"
#include "colors.h"
#include <iostream>
#include <cassert>
#include <ostream>
#include <utility>
#include <vector>
#include <prettyPrint.h>

using namespace std;

int main() {
  ProductExceptSelf soln;
  vector<pair<vector<int>, vector<int>>> testCases = {
    { {}, {} },
    { {1}, {} },
    { {1,2}, {2,1} },
    { {1,2,3}, {6,3,2} },
    { {-1,2,3}, {6,-3,-2} },
    { {0,2,3}, {6,0,0} },
    { {3,2,4,-1,-5}, {40,60,30,-120,-24} },
  };

  for (pair<vector<int>,vector<int>> test : testCases) {
    vector<int> &nums = test.first, &answer = test.second;
    colorOut(colors::BLUE, "test: ") << prettyString(nums)
      << " => " << prettyString(answer) << endl;
    vector<int> result = soln.productExceptSelf(nums);
    colorOut(colors::LIGHT_YELLOW, " --> ") << prettyString(result) << " ";
    if (result == answer)
      colorOut(colors::GREEN, "PASS");
    else
      colorOut(colors::RED, "FAIL");
    cout << endl;
  }
}

