#include "AccountsMerge.h"
#include <vector>
#include <string>
#include <prettyPrint.h>

using namespace std;

int main() {
  Solution soln;
  vector<vector<string>> accounts {
    {
      {"Dave","Dave0@m.co","Dave5@m.co","Dave0@m.co"},
      {"Lily","Lily4@m.co","Lily2@m.co","Lily0@m.co"},
      {"Fern","Fern5@m.co","Fern2@m.co","Fern6@m.co"},
      {"Gabe","Gabe0@m.co","Gabe6@m.co","Gabe8@m.co"},
      {"Alex","Alex7@m.co","Alex5@m.co","Alex7@m.co"},
      {"Lily","Lily4@m.co","Lily6@m.co","Lily7@m.co"},
      {"Alex","Alex0@m.co","Alex4@m.co","Alex5@m.co"},
      {"John","John4@m.co","John2@m.co","John0@m.co"},
    }
  };
  vector<vector<string>> result = soln.accountsMerge(accounts);
  prettyPrint2D(result);
}

