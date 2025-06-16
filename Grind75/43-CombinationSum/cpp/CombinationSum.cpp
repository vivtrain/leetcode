#include "CombinationSum.h"
#include <vector>

using namespace std;

void Solution::combinationSum3_recurse(
    const vector<int>& candidates,
    const size_t index,
    const int target,
    vector<vector<int>>& results) {
  // Done, no more candidates possible
  if (index >= candidates.size() || target < 0)
    return;
  if (target == 0) {
    results.emplace_back();
    return;
  }
  int cand = candidates[index];
  // Case 1: Take candidate, recurse on rest, add candidate to results
  if (cand <= target) {
    size_t combsBefore = results.size();
    combinationSum3_recurse(candidates, index, target - cand, results);
    for (size_t r = combsBefore; r < results.size(); r++)
      results[r].push_back(cand);
  }
  // Case 2: Skip the current candidate
  combinationSum3_recurse(candidates, index + 1, target, results);
  return;
}

vector<vector<int>> Solution::combinationSum3(
    vector<int>& candidates,
    int target) {
  if (candidates.empty() && target == 0)
    return {{}};
  else if (candidates.empty())
    return {};
  vector<vector<int>> results;
  combinationSum3_recurse(candidates, 0, target, results);
  return results;
}

vector<vector<int>> Solution::combinationSum2_recurse(
    const vector<int>& candidates,
    const size_t index,
    const int target) {
  // Done, no more candidates possible
  if (index == candidates.size() || target < 0)
    return {};
  if (target == 0)
    return {{}};
  int curCandidate = candidates[index];
  vector<vector<int>> results;
  // Case 1: Take candidate, recurse on rest, add candidate to results
  if (curCandidate <= target) {
    vector<vector<int>> resultsIfTake
      = combinationSum2_recurse(candidates, index, target - curCandidate);
    for (vector<int> &r : resultsIfTake)
      r.push_back(curCandidate);
    results.insert(results.end(), resultsIfTake.begin(), resultsIfTake.end());
  }
  // Case 2: Skip the current candidate
  vector<vector<int>> resultsIfSkip
    = combinationSum2_recurse(candidates, index + 1, target);
  results.insert(results.end(), resultsIfSkip.begin(), resultsIfSkip.end());
  return results;
}

vector<vector<int>> Solution::combinationSum2(
    vector<int>& candidates,
    int target) {
  if (candidates.empty() && target == 0)
    return {{}};
  else if (candidates.empty())
    return {};
  return combinationSum2_recurse(candidates, 0, target);
}

vector<vector<int>> Solution::combinationSum(
    vector<int>& candidates,
    int target) {
  if (candidates.empty() && target == 0)
    return {{}};
  else if (candidates.empty())
    return {};
  vector< vector<vector<int>> > memo(target + 1);
  memo[0].emplace_back();
  for (int t = 1; t <= target; t++) {
    for (int c : candidates) {
      if (t - c < 0)
        continue;
      for (vector<int> &comb : memo[t-c]) {
        if (!comb.empty() && c < comb.back())
          continue;
        vector<int> newComb(comb);
        newComb.push_back(c);
        memo[t].push_back(std::move(newComb));
      }
    }
  }
  return memo[target];
}

