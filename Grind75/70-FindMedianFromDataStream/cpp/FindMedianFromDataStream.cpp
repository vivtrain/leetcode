#include "FindMedianFromDataStream.h"
#include <cstdio>
#include <set>

using namespace std;

// Min-Max Heaps Solution ┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈

MedianFinder::MedianFinder() : minHeap(), maxHeap() {}

void MedianFinder::addNum(int num) {
  if (num > findMedian())
    minHeap.push(num);
  else
    maxHeap.push(num);

  if (minHeap.size() > maxHeap.size() + 1) {
    maxHeap.push(minHeap.top());
    minHeap.pop();
  } else if (maxHeap.size() > minHeap.size() + 1) {
    minHeap.push(maxHeap.top());
    maxHeap.pop();
  }
}

double MedianFinder::findMedian() {
  if (minHeap.empty() && maxHeap.empty())
    return 0.0;
  else if (minHeap.size() > maxHeap.size()) {
    return minHeap.top();
  } else if (minHeap.size() < maxHeap.size()) {
    return maxHeap.top();
  } else {
    return (minHeap.top() + maxHeap.top()) / 2.0;
  }
}

// Multiset Solution ┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈

MedianFinder2::MedianFinder2() : nums(), mid(nums.end()) {}

void MedianFinder2::addNum(int num) {
  nums.insert(num);
  if (nums.size() == 1)
    mid = nums.begin();
  else if (evenLength() && num < *mid)
    mid--;
  else if (!evenLength() && num >= *mid)
    mid++;
}

double MedianFinder2::findMedian() {
  if (mid == nums.end())
    return 0.0;
  return evenLength() ? (*mid + *(next(mid))) / 2.0 : *mid;
}

