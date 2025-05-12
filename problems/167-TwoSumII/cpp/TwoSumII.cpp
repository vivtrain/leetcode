#include "TwoSumII.h"
#include <vector>

using namespace std;

vector<int> TwoSumII::twoSum(vector<int>& numbers, int target) {
  if (numbers.size() < 2)
    return {};
  for (int l=0, r=numbers.size()-1; l < r;) {
    int sum = numbers[l] + numbers[r];
    if (sum < target)
      l++;
    else if (sum > target)
      r--;
    else
      return {l+1, r+1};
  }
  return {};
}

