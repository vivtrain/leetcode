#include "KClosestPoints.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <tuple>
#include <prettyPrint.h>
#include <string>

using namespace std;

string strPoints(const vector<vector<int>> &points) {
  string str("[");
  for (const vector<int> &point : points)
    str += prettyString(point)  + ',';
  if (!points.empty())
    *(str.end()-1) = ']';
  else
    str += ']';
  return str;
}

int main() {
  KClosestPoints soln;
  vector<tuple<vector<vector<int>>, int, vector<vector<int>>>> testCases {
    { {{0,0}, {-1,0}, {2,0}, {0,3}, {0,-4}}, 2, {{0,0}, {-1,0}} },
  };

  bool success = true;
  for (auto test : testCases) {
    vector<vector<int>> &inPoints = get<0>(test);
    int k = get<1>(test);
    vector<vector<int>> &outPoints = get<2>(test);
    cout << strPoints(inPoints) << " --> " << strPoints(outPoints) << endl;
    vector<vector<int>> result = soln.kClosest_minHeap(inPoints, k);
    if (result != outPoints) {
      cout << "\e[31mFAIL\e[0m --> " << strPoints(result) << endl;
      success = false;
    }
  }
  if (success)
    cout << "\e[32mTESTS PASSED!\e[0m" << endl;
}

