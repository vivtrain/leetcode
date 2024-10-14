#ifndef K_CLOSEST_POINTS
#define K_CLOSEST_POINTS
#include <cmath>
#include <vector>

class KClosestPoints {
  public:
    std::vector<std::vector<int>> kClosest_sort(
        std::vector<std::vector<int>>& points,
        int k);
    std::vector<std::vector<int>> kClosest_minHeap(
        std::vector<std::vector<int>>& points,
        int k);
  private:
    bool compareNorm(const std::vector<int> &a, const std::vector<int> &b) {
      double distA = sqrt((a[0]*a[0] + a[1]*a[1]));
      double distB = sqrt((b[0]*b[0] + b[1]*b[1]));
      return (distA < distB);
    }
};

#endif

