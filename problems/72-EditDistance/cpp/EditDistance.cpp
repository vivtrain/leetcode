#include "EditDistance.h"
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include "prettyPrint.h"

using namespace std;

int minDistance_recurse(
    const string &word1,
    size_t pos1,
    const string &word2,
    size_t pos2,
    int soFar,
    int &best) {
  if (soFar >= best)
    return best;
  if (pos2 == word2.size()) {
    best = min(int(soFar + word1.size() - pos1), best);
    return best;
  } else if (pos1 == word1.size()) {
    best = min(int(soFar + word2.size() - pos2), best);
    return best;
  }
  char c1 = word1[pos1], c2 = word2[pos2];
  if (c1 == c2) {
    best = minDistance_recurse(word1, pos1+1, word2, pos2+1, soFar, best);
    return best;
  } else {
    best = minDistance_recurse(word1, pos1+1, word2, pos2+1, soFar+1, best);
    best = minDistance_recurse(word1, pos1,   word2, pos2+1, soFar+1, best);
    best = minDistance_recurse(word1, pos1+1, word2, pos2,   soFar+1, best);
    return best;
  }
}

int Solution::minDistance2(string word1, string word2) {
  int worst = word2.size() + abs(int(word2.size()) - int(word1.size()));
  return minDistance_recurse(word1, 0, word2, 0, 0, worst);
}

int Solution::minDistance(string word1, string word2) {
  int worst = word2.size() + abs(int(word2.size()) - int(word1.size()));
  vector<vector<int>> memo(word1.size()+1, vector<int>(word2.size()+1, worst));
  for (uint p1 = 0; p1 <= word1.size(); p1++)
    memo[p1][word2.size()] = word1.size() - p1;
  for (uint p2 = 0; p2 <= word2.size(); p2++)
    memo[word1.size()][p2] = word2.size() - p2;
  for (int pos1 = word1.size() - 1; pos1 >= 0; pos1--) {
    for (int pos2 = word2.size() -1; pos2 >= 0; pos2--) {
      if (word1[pos1] == word2[pos2]) {
        memo[pos1][pos2] = memo[pos1+1][pos2+1];
      } else {
        memo[pos1][pos2] = min({
          memo[pos1+1][pos2+1] + 1, // replace
          memo[pos1+1][pos2]   + 1, // delete
          memo[pos1]  [pos2+1] + 1, // insert
        });
      }
    }
  }
  return memo[0][0];
}

