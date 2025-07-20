#ifndef FIND_MEDIAN_FROM_DATA_STREAM
#define FIND_MEDIAN_FROM_DATA_STREAM

#include <functional>
#include <queue>
#include <set>
#include <vector>

// Min-Max Heaps Solution ┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈
class MedianFinder {
  public:
    MedianFinder();
    void addNum(int num);
    double findMedian();
  private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;
};

// Multiset Solution ┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈
class MedianFinder2 {
  public:
    MedianFinder2();
    void addNum(int num);
    double findMedian();
  private:
    std::multiset<int> nums;
    std::multiset<int>::iterator mid;
    inline bool evenLength() { return nums.size() % 2 == 0; }
};

#endif

