#include "FindMedianFromDataStream.h"
#include <cassert>
#include <iostream>
#include <prettyPrint.h>

using namespace std;
using namespace colors;

int main() {
  MedianFinder mf;
  double result;
  result = mf.findMedian();
  cout << result << endl;
  assert(result == 0.0);
  mf.addNum(1);
  result = mf.findMedian();
  cout << result << endl;
  assert(result == 1.0);
  mf.addNum(2);
  result = mf.findMedian();
  cout << result << endl;
  assert(result == 1.5);
  mf.addNum(3);
  result = mf.findMedian();
  result = mf.findMedian();
  cout << result << endl;
  assert(result == 2.0);
}

