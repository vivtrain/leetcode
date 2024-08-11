#ifndef FIRST_BAD_VERSION
#define FIRST_BAD_VERSION

class FirstBadVersion {
  public:
    int firstBadVersion(int n);
    int bad = 0;
    int n = 0;
  private:
    int firstBadVersion_recurse(int m, int n);
    bool isBadVersion(int version) {
      if (version < 1 || version > n)
        throw;
      return version >= bad;
    }
};

#endif

