#include "KClosestPoints.h"
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Approach: Custom comparator for std::sort
vector<vector<int>> KClosestPoints::kClosest_sort(
    vector<vector<int>>& points,
    int k) {
  sort(points.begin(), points.end(),
      [this](const vector<int> &a, const vector<int> &b) {
        return this->compareNorm(a, b);
      });
  points.resize(k);
  return points;
}

// Approach: MinHeap
vector<vector<int>> KClosestPoints::kClosest_minHeap(
    vector<vector<int>>& points,
    int k) {
  auto comparator = [this](const vector<int> &a, const vector<int> &b) {
        return !this->compareNorm(a, b);
      };
  priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> heap(
      points.begin(),
      points.end(),
      comparator);
  vector<vector<int>> result(k);
  for (int i = 0; i < k; i++) {
    result[i] = heap.top();
    heap.pop();
  }
  return result;
}

