#include "SearchRotatedArray.h"
#include <iostream>
#include <vector>
#include <prettyPrint.h>

using namespace std;

int main() {
  Solution soln;
  vector<int> test;
  int size = 100;
  int pivot = 5;
  for (int i = size - pivot + 1; i <= size; i++)
    test.push_back(i);
  for (int i = 1; i <= size - pivot; i++)
    test.push_back(i*2);
  prettyPrint(test);
  int search = 22;
  int result = soln.search(test, 22);
  if (result == -1)
    cout << "did not find " << search << endl;
  else
    cout << "found " << search << " at index " << result << endl;
}

