#ifndef WORD_LADDER
#define WORD_LADDER

#include <string>
#include <vector>

class Solution {
  public:
    int ladderLength(
        std::string beginWord,
        std::string endWord,
        std::vector<std::string>& wordList);
    int ladderLength2(
        std::string beginWord,
        std::string endWord,
        std::vector<std::string>& wordList);
};

#endif

