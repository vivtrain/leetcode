#include "SpiralMatrix.h"
#include <vector>
#include <prettyPrint.h>

using namespace std;

int main() {
  Solution soln;
  vector<vector<int>> matrix {
    { 1, 2, 3, 4},
    {12,13,14, 5},
    {11,16,15, 6},
    {10, 9, 8, 7},
  };
  prettyPrint2D(matrix);
  prettyPrint(soln.spiralOrder(matrix));
}

