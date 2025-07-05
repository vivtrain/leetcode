#include "UniquePaths.h"
#include "prettyPrint.h"
#include <vector>

using namespace std;

int Solution::uniquePaths(int m, int n) {
  if (m <= 0 || n <= 0)
    return 0;
  vector<int> cache(n);
  for (int r = m-1; r >= 0; r--) {
    for (int c = n-1; c >= 0; c--) {
      if (r == m-1 || c == n-1) {
        cache[c] = 1;
      } else {
        cache[c] = cache[c] + cache[c+1];
      }
    }
  }
  return cache[0];
}

int Solution::uniquePaths2(int m, int n) {
  if (m <= 0 || n <= 0)
    return 0;
  vector<vector<int>> cache(m, vector<int>(n));
  for (int r = m-1; r >= 0; r--) {
    for (int c = n-1; c >= 0; c--) {
      if (r == m-1 || c == n-1) {
        cache[r][c] = 1;
      } else {
        cache[r][c] = cache[r+1][c] + cache[r][c+1];
      }
    }
  }
  prettyPrint2D(cache);
  return cache[0][0];
}

