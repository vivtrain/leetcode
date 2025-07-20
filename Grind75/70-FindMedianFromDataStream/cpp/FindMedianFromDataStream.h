#ifndef FIND_MEDIAN_FROM_DATA_STREAM
#define FIND_MEDIAN_FROM_DATA_STREAM

#include <set>
class MedianFinder {
  public:
    MedianFinder();
    void addNum(int num);
    double findMedian();
  private:
    std::multiset<int> nums;
    std::multiset<int>::iterator mid;
    inline bool evenLength() { return nums.size() % 2 == 0; }
};

#endif

