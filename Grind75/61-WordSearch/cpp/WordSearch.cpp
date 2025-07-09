#include "WordSearch.h"
#include <vector>
#include <string>

using namespace std;

bool Solution::dfs(
    vector<vector<char>> &board, const uint &r, const uint &c,
    const string &word, const uint &wordPos) {
  if (!(0 <= r && r < board.size() && 0 <= c && c < board[0].size()))
    return false; // out of bounds
  else if (board[r][c] == '\0')
    return false; // visited
  else if (board[r][c] != word[wordPos])
    return false; // fail
  else if (wordPos == word.size()-1 && board[r][c] == word[wordPos])
    return true; // success
  char orig = board[r][c];
  board[r][c] = '\0';
  if (   dfs(board, r+1, c, word, wordPos+1)
      || dfs(board, r-1, c, word, wordPos+1)
      || dfs(board, r, c+1, word, wordPos+1)
      || dfs(board, r, c-1, word, wordPos+1) )
    return true;
  board[r][c] = orig;
  return false;
}

bool Solution::exist(vector<vector<char>>& board, string word) {
  if (word.empty())
    return true;
  if (board.empty() || board[0].empty())
    return false;
  uint nRows = board.size(), nCols = board[0].size();
  if (word.size() > nRows * nCols)
    return false;

  for (uint r = 0; r < nRows; r++) {
    for (uint c = 0; c < nCols; c++) {
      if (board[r][c] == word[0] && dfs(board, r, c, word, 0))
        return true;
    }
  }
  return false;
}

