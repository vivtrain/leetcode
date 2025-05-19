#include "CourseSchedule.h"
#include "colors.h"
#include <iostream>
#include <prettyPrint.h>
#include <cassert>
#include <vector>
#include <tuple>

using namespace std;
using namespace colors;

int main() {
  CourseSchedule soln;
  vector<tuple<int, vector<vector<int>>, bool>> testCases = {
    { 3, {}, true },
    { 3, {{0,0}}, false },
    { 3, {{1,0}}, true },
    { 3, {{1,0},{0,1}}, false },
    { 3, {{2,1},{1,0}}, true },
    { 3, {{2,1},{2,0}}, true },
    { 3, {{2,1},{0,1}}, true },
    { 3, {{2,1},{2,0}}, true },
    { 3, {{2,1},{2,0},{1,0}}, true },
    { 3, {{2,1},{1,0},{0,2}}, false },
    { 3, {{0,2},{1,2},{2,0}}, false },
    { 3, {{1,0},{1,2},{0,1}}, false },
    { 5, {{2,0},{1,2},{1,0},{3,1},{0,3}}, false },
    { 3, {{1,2},{2,1},{1,0},{2,0}}, false },
    { 4, {{3,0},{2,1},{1,3},{0,2}}, false },
    { 4, {{1,0},{2,0},{3,0},{1,3},{2,1},{3,2}}, false },
    { 7, {{1,0},{0,3},{0,2},{3,2},{2,5},{4,5},{5,6},{2,4}}, true},
  };

  for (auto test : testCases) {
    int nCourses = get<0>(test);
    vector<vector<int>> prereqs = vector<vector<int>>(get<1>(test));
    bool isValid = get<2>(test);
    colorOut(LIGHT_BLUE, "TEST: ") << nCourses << " courses, prereqs: ";
    for (auto p : prereqs)
      cout << prettyString(p) << " ";
    cout << endl;
    bool result = soln.canFinish(nCourses, prereqs);
    cout << boolalpha << "\t(acutal) " << isValid << " ?= " << result << " ";
    ((result == isValid) ? colorOut(GREEN, "PASS") : colorOut(RED, "FAIL")) << endl;
  }
}

