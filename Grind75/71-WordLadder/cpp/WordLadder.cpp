#include "WordLadder.h"
#include <queue>
#include <string>
#include <sys/types.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int Solution::ladderLength(
    string beginWord,
    string endWord,
    vector<string>& wordList) {

  unordered_set<string> wordSet(wordList.begin(), wordList.end());
  if (wordSet.count(endWord) == 0)
    return 0;

  queue<pair<string, uint>> bfs;
  bfs.push({beginWord, 0});

  while (!bfs.empty()) {
    auto [word, dist] = bfs.front();
    bfs.pop();
    if (word == endWord)
      return dist + 1;
    for (uint w = 0; w < word.size(); w++) {
      char orig = word[w];
      for (char l = 'a'; l <= 'z'; l++) {
        word[w] = l;
        if (wordSet.count(word) > 0) {
          bfs.push({word, dist + 1});
          wordSet.erase(word);
        }
      }
      word[w] = orig;
    }
  }
  return 0;
}

inline bool oneAway(const string& a, const string& b) {
  if (a.size() != b.size())
    return false;
  uint diffs = 0;
  for (uint i = 0; i < a.size(); i++) {
    if (a[i] != b[i])
      diffs++;
    if (diffs > 1)
      return false;
  }
  return diffs == 1;
}

int Solution::ladderLength2(
    string beginWord,
    string endWord,
    vector<string>& wordList) {
  wordList.push_back(beginWord);
  unordered_map<string, vector<string>> adj;
  for (uint i = 0; i < wordList.size(); i++) {
    const string &wi = wordList[i];
    for (uint j = i+1; j < wordList.size(); j++) {
      const string &wj = wordList[j];
      if (oneAway(wi, wj)) {
        adj[wi].push_back(wj);
        adj[wj].push_back(wi);
      }
    }
  }

  queue<pair<string, uint>> bfs;
  bfs.push({beginWord, 0});
  unordered_set<string> visited;
  visited.insert(beginWord);

  while (!bfs.empty()) {
    auto [word, dist] = bfs.front();
    bfs.pop();
    if (word == endWord)
      return dist + 1;
    for (const string &nbr : adj[word]) {
      if (visited.count(nbr) > 0)
        continue;
      bfs.push({nbr, dist + 1});
      visited.insert(nbr);
    }
  }
  return 0;
}

