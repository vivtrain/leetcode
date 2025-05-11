#include "ThreeSum.h"
#include "prettyPrint.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ThreeSum::threeSum(vector<int>& nums) {
  if (nums.size() < 3)
    return {};

  vector<vector<int>> results;
  sort(nums.begin(), nums.end());
  prettyPrint(nums);

  for (size_t i = 0; i < nums.size()-2;) {
    size_t l = i+1, r = nums.size()-1;
    cout << "i: " << i;

    while (l < r) {
      cout << ", l: " << l << ", r: " << r << endl;
      int sum = nums[i] + nums[l] + nums[r];
      if (sum < 0) 
        do l++; while (l < r && nums[l-1] == nums[l]);
      else if (sum > 0)
        do r--; while (l < r && nums[r] == nums[r+1]);
      else {
        results.push_back({nums[i], nums[l], nums[r]});
        cout << "hit\n";
        do l++; while (l < r && nums[l-1] == nums[l]);
      }
    }

    do i++; while (i < nums.size()-2 && nums[i-1] == nums[i]);
  }

  return results;
}

