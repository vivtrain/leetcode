#include "FirstBadVersion.h"

int FirstBadVersion::firstBadVersion_recurse(int m, int n) {
  if (m == n)
    return n;
  if (n-m==1 && !isBadVersion(m) && isBadVersion(n))
    return n;
  int mid = m + (n-m)/2;
  if (isBadVersion(mid))
    return firstBadVersion_recurse(m, mid);
  else
    return firstBadVersion_recurse(mid, n);
}

int FirstBadVersion::firstBadVersion(int n) {
  return firstBadVersion_recurse(1, n);
}

