#ifndef WORD_SEARCH
#define WORD_SEARCH

#include <vector>
#include <string>

class Solution {
  public:
    bool exist(std::vector<std::vector<char>>& board, std::string word);
  private:
    bool dfs(
        std::vector<std::vector<char>> &board,
        const uint &r, const uint &c,
        const std::string &word, const uint &wordPos);
};

#endif

