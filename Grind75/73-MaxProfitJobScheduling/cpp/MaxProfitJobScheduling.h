#ifndef MAX_PROFIT_JOB_SCHEDULING
#define MAX_PROFIT_JOB_SCHEDULING

#include <sys/types.h>
#include <tuple>
#include <vector>

class Solution {
  public:
    int jobScheduling(
        std::vector<int>& startTime,
        std::vector<int>& endTime,
        std::vector<int>& profit);
    int jobScheduling2(
        std::vector<int>& startTime,
        std::vector<int>& endTime,
        std::vector<int>& profit);
    int jobScheduling3(
        std::vector<int>& startTime,
        std::vector<int>& endTime,
        std::vector<int>& profit);
  private:
    int schedule(
        std::vector<std::tuple<int, int, int>> &jobs,
        uint index, int lastEnd);
    int endBeforeStart(int index, std::vector<std::tuple<int, int, int>> &jobs);
};

#endif

