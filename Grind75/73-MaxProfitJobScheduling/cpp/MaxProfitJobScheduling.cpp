#include "MaxProfitJobScheduling.h"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <iterator>
#include <sys/types.h>
#include <tuple>
#include <vector>

using namespace std;

int Solution::schedule(vector<tuple<int, int, int>> &jobs, uint index, int lastEnd) {
  if (index >= jobs.size())
    return 0;
  const auto &[start, end, profit] = jobs[index];
  int skip = schedule(jobs, index + 1, lastEnd);
  if (start < lastEnd)
    return skip;
  int take = profit + schedule(jobs, index + 1, end);
  return max(take, skip);
}

int Solution::jobScheduling2(
    vector<int>& startTime,
    vector<int>& endTime,
    vector<int>& profit) {
  vector<tuple<int, int, int>> jobs;
  for (uint i = 0; i < startTime.size(); i++)
    jobs.push_back({startTime[i], endTime[i], profit[i]});
  std::sort(jobs.begin(), jobs.end());
  return schedule(jobs, 0, 0);
}

int Solution::endBeforeStart(int index, vector<tuple<int, int, int>> &jobs) {
  const int &start = get<1>(jobs[index]);
  int left = 0, right = index - 1;
  while (left <= right) {
    int center = (left + right) / 2;
    const int &end = get<0>(jobs[center]);
    if (end < start) {
      left = center + 1;
    } else if (end > start) {
      right = center - 1;
    } else {
      right = center;
      break;
    }
  }
  int best = right;
  while (best + 1 < index && get<0>(jobs[best+1]) <= start)
    best++;
  return best;
}

int Solution::jobScheduling3(
    vector<int>& startTime,
    vector<int>& endTime,
    vector<int>& profit) {
  if (startTime.empty())
    return 0;

  vector<tuple<int, int, int>> jobs;
  for (uint i = 0; i < startTime.size(); i++)
    jobs.push_back({endTime[i], startTime[i], profit[i]});
  std::sort(jobs.begin(), jobs.end());

  vector<int> bestProfit(jobs.size(), 0);
  for (uint j = 0; j < jobs.size(); j++) {
    const auto &[end, start, profit] = jobs[j];
    const int lastEnd = endBeforeStart(j, jobs);
    const int lastBest = lastEnd >= 0 ? bestProfit[lastEnd] : 0;
    const int prev = j > 0 ? bestProfit[j-1] : 0;
    bestProfit[j] = max(prev, lastBest + profit);
  }
  return bestProfit.back();
}


int Solution::jobScheduling(
    vector<int>& startTime,
    vector<int>& endTime,
    vector<int>& profit) {
  if (startTime.empty())
    return 0;

  vector<tuple<int, int, int>> jobs;
  for (uint i = 0; i < startTime.size(); i++)
    jobs.push_back({endTime[i], startTime[i], profit[i]});
  sort(jobs.begin(), jobs.end());

  vector<int> cache(jobs.size(), 0);
  for (uint j = 0; j < jobs.size(); j++) {
    const auto &[end, start, profit] = jobs[j];
    const tuple<int, int, int> search {start, INT32_MAX, INT32_MAX};
    const int lastEnd =
      upper_bound(jobs.begin(), jobs.end(), search) - jobs.begin() - 1;
    const int lastBest = lastEnd >= 0 ? cache[lastEnd] : 0;
    const int prev = j > 0 ? cache[j-1] : 0;
    cache[j] = max(prev, lastBest + profit);
  }
  return cache.back();
}
 
