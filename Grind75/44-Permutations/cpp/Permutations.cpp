#include "Permutations.h"
#include <vector>
#include <queue>

using namespace std;

void Solution::permute(queue<int>& nums, vector<int>& perm, vector<vector<int>>& permutations) {
  if (nums.empty()) {
    permutations.push_back(perm);
    return;
  }
  for (size_t i = 0; i < nums.size(); i++) {
    int num = nums.front();
    nums.pop();
    perm.push_back(num);
    permute(nums, perm, permutations);
    perm.pop_back();
    nums.push(num);
  }
}

vector<vector<int>> Solution::permute(vector<int>& nums) {
  vector<vector<int>> permutations;
  vector<int> perm;
  queue<int> numsQ;
  for (int n : nums)
    numsQ.push(n);
  permute(numsQ, perm, permutations);
  return permutations;
}

