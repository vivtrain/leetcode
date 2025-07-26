#include "LargestRectangleInHistorgram.h"
#include <cstdio>
#include <stack>
#include <sys/types.h>
#include <vector>

using namespace std;

int Solution::largestRectangleArea(vector<int>& heights) {
  heights.push_back(-1);
  int maxArea = 0;
  stack<int> startStack, heightStack;
  for (uint end = 0; end < heights.size(); end++) {
    int start = end, height = heights[start];
    while (!startStack.empty() && heights[end] < heightStack.top()) {
      start = startStack.top();
      height = heightStack.top();
      int width = end - start;
      int area = height * width;
      if (area > maxArea)
        maxArea = area;
      startStack.pop();
      heightStack.pop();
    }
    startStack.push(start);
    heightStack.push(heights[end]);
  }
  return maxArea;
}

