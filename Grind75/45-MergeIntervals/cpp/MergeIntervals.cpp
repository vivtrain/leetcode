#include "MergeIntervals.h"
#include <algorithm>
#include <list>
#include <vector>
#include <prettyPrint.h>

using namespace std;

inline bool compare(const vector<int> &left, const vector<int> &right) {
  return left[0] < right[0];
}

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals) {
  if (intervals.size() < 2)
    return intervals;
  sort(intervals.begin(), intervals.end(), compare);
  vector<vector<int>> result;
  result.push_back(intervals.front());
  for (size_t i = 1; i < intervals.size(); i++) {
    vector<int> &iv = intervals[i];
    vector<int> &prev = result.back();
    if (iv[0] <= prev[1])
      prev[1] = max(iv[1], prev[1]);
    else
      result.push_back(iv);
  }
  return result;
}

vector<vector<int>> Solution::merge2(vector<vector<int>>& intervals) {
  if (intervals.size() < 2)
    return intervals;
  sort(intervals.begin(), intervals.end(), compare);
  list<vector<int>> iList;
  iList.insert(iList.begin(), intervals.begin(), intervals.end());
  list<vector<int>>::iterator prev = iList.begin();
  list<vector<int>>::iterator it = ++iList.begin();
  while (it != iList.end()) {
    if ((*it)[0] <= (*prev)[1]) {
      (*prev)[1] = max((*it)[1], (*prev)[1]);
      it = iList.erase(it);
    } else {
      it++;
      prev++;
    }
  }
  vector<vector<int>> result;
  result.insert(result.begin(), iList.begin(), iList.end());
  return result;
}

