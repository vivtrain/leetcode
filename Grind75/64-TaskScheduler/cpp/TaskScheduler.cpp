#include "TaskScheduler.h"
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

int Solution::leastInterval(vector<char>& tasks, int n) {
  array<int, 26> counts;
  for (int &c : counts) c = 0;
  for (const char &c : tasks)
    counts[c - 'A']++;

  sort(counts.begin(), counts.end());
  int chunkSize = n + 1;
  int nSlots = chunkSize * counts[25];
  int countMax = 0;
  for (int c = 25; c >= 0; c--) {
    if (counts[c] == counts[25])
      countMax++;
    else
      break;
  }
  return max(nSlots - chunkSize + countMax, int(tasks.size()));
}

