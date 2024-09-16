#include "ZeroOneMatrix.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <prettyPrint.h>

using namespace std;

int main() {
  ZeroOneMatrix soln;

  vector<pair<vector<vector<int>>, vector<vector<int>>>> testCases {
    { {{0}}, {{0}} },
    { {{0,1}}, {{0,1}} },
    { {{0,1},{1,1}}, {{0,1},{1,2}} },
    { {{0,1},{1,0}}, {{0,1},{1,0}} },
    { {{0,1,1},{1,1,0},{1,1,1}}, {{0,1,1},{1,1,0},{2,2,1}} },
  };

  vector<vector<int>> largeMat(50, vector<int>(50, 1));
  largeMat[0][49] = 0;
  largeMat[20][10] = 0;
  largeMat[35][25] = 0;
  largeMat[32][30] = 0;
  prettyPrint2D(soln.updateMatrix(largeMat));

  bool success = true;
  for (auto test : testCases) {
    prettyPrint2D(test.first);
    prettyPrint2D(test.second);
    vector<vector<int>> result = soln.updateMatrix(test.first);
    if (result != test.second) {
      success = false;
      cout << "\e[31mFAIL\e[0m" << endl;
      prettyPrint2D(result);
    }
      cout << endl;
  }
  if (success) {
    cout << "\e[32mTESTS PASSED!\e[0m" << endl;
  }
}

