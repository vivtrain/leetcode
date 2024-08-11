#include "FirstBadVersion.h"

int FirstBadVersion::firstBadVersion(int n) {
  int low = 1, high = n, mid;
  while (low < high) {
    mid = low + (high-low)/2;
    if (isBadVersion(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

int FirstBadVersion::firstBadVersion2_recurse(int m, int n) {
  if (m == n)
    return n;
  if (n-m==1 && !isBadVersion(m) && isBadVersion(n))
    return n;
  int mid = m + (n-m)/2;
  if (isBadVersion(mid))
    return firstBadVersion2_recurse(m, mid);
  else
    return firstBadVersion2_recurse(mid, n);
}

int FirstBadVersion::firstBadVersion2(int n) {
  return firstBadVersion2_recurse(1, n);
}

int FirstBadVersion::firstBadVersion3(int n) {
  if (n == 1)
    return 1;
  int version = n, jump = n/2;
  while (jump > 0) {
    if (isBadVersion(version))
      version -= jump;
    else
      version += jump;
    jump /= 2;
  }
  int prev = version;
  if (isBadVersion(version)) {
    while (version >= 1 && isBadVersion(version)) {
      prev = version;
      version--;
    }
    return prev;
  } else {
    while (version <= n && !isBadVersion(version)) {
      prev = version;
      version++;
    }
    return version;
  }
}

