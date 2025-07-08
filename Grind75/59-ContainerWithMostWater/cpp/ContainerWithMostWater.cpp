#include "ContainerWithMostWater.h"
#include <vector>

using namespace std;

int Solution::maxArea(vector<int>& height) {
  int left = 0, right = height.size() - 1;
  int bestArea = 0;
  while (left < right) {
    int area = (right - left) * min(height[left], height[right]);
    if (area > bestArea)
      bestArea = area;
    if (height[left] < height[right])
      left++;
    else
      right--;
  }
  return bestArea;
}

