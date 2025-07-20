#include "FindMedianFromDataStream.h"
#include <cstdio>
#include <set>

using namespace std;

MedianFinder::MedianFinder() : nums(), mid(nums.end()) {}

void MedianFinder::addNum(int num) {
  nums.insert(num);
  if (nums.size() == 1)
    mid = nums.begin();
  else if (evenLength() && num < *mid)
    mid--;
  else if (!evenLength() && num >= *mid)
    mid++;
}

double MedianFinder::findMedian() {
  if (mid == nums.end())
    return 0.0;
  return evenLength() ? (*mid + *(next(mid))) / 2.0 : *mid;
}

