#include "TwoSum.h"
#include <vector>
#include <tuple>
#include <prettyPrint.h>

// Include specific namespaces for better readability
using std::vector;
using std::tuple;
using std::get;
using testCase = tuple<vector<int>, int>;

testCase newTestCase(vector<int> input, int target) {
  return tuple<vector<int>, int>(vector<int>(input), target);
}

int main() {
  // Setup inputs and outputs for test cases
  TwoSum twoSum;
  // Vector of tuples, each tuple containing in-vector, target, and out-vector
  vector<testCase> tests;
  tests.push_back(newTestCase({1,2,3,4}, 5));
  tests.push_back(newTestCase({1,3,2,4}, 6));
  tests.push_back(newTestCase({1,3,4,2}, 6));

  // Run tests and manually verify
  for (auto test : tests) {
    vector<int> result = twoSum.twoSum(get<0>(test), get<1>(test));
    prettyPrint(result);
  }
}

