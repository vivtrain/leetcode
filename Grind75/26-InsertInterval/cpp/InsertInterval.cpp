#include "InsertInterval.h"
#include <vector>

using std::vector;

vector<vector<int>> InsertInterval::insert(vector<vector<int>>& intervals,
                                           vector<int>& newInterval) {
  size_t begin_erase = intervals.size();
  size_t end_erase = intervals.size();
  size_t insert_at = 0;
  for (size_t i = 0; i < intervals.size(); i++) {
    if ((newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]) ||
        (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) ||
        (newInterval[0] <= intervals[i][0] && newInterval[1] >= intervals[i][1])) {
      // Overlapping interval
      if (intervals[i][0] < newInterval[0])
        newInterval[0] = intervals[i][0];
      if (intervals[i][1] > newInterval[1])
        newInterval[1] = intervals[i][1];
      if (begin_erase == intervals.size())
        begin_erase = i;
      end_erase = i+1;
    }
    if (newInterval[0] > intervals[i][1])
      insert_at++;
  }
  intervals.erase(intervals.begin()+begin_erase, intervals.begin()+end_erase);
  intervals.insert(intervals.begin()+insert_at, newInterval);
  return intervals;
}

