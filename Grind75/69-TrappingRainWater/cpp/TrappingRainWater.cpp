#include "TrappingRainWater.h"
#include <vector>

using namespace std;

int Solution::trap(vector<int>& height) {
  if (height.size() < 3)
    return 0;
  int leftWall = 0, rightWall = 1;
  int volume = 0, total = 0;
  for (rightWall = 1; rightWall < int(height.size()); rightWall++) {
    if (height[leftWall] <= height[rightWall]) {
      total += volume;
      volume = 0;
      leftWall = rightWall;
    } else {
      volume += height[leftWall] - height[rightWall];
    }
  }
  volume = 0;
  rightWall = height.size()-1;
  int lastLeft = leftWall;
  for (leftWall = height.size() - 2; leftWall >= lastLeft; leftWall--) {
    if (height[leftWall] >= height[rightWall]) {
      total += volume;
      volume = 0;
      rightWall = leftWall;
    } else {
      volume += height[rightWall] - height[leftWall];
    }
  }
  return total;
}

