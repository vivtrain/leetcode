#include "WordBreak.h"
#include "prettyPrint.h"
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool Solution::wordBreak(string s, vector<string> &wordDict) {
  unordered_set<string> dict;
  dict.insert(wordDict.begin(), wordDict.end());
  if (s.empty())
    return true;

  vector<bool> wordEnd(s.size()+1, false);
  wordEnd[0] = true;

  int maxSize = 0;
  for (const string &word : wordDict) {
    if (int(word.size()) > maxSize)
      maxSize = word.size();
  }

  for (int end = 1; end < int(s.size()+1); end++) {
    for (int begin = end - 1; begin >= 0 && end - begin <= maxSize; begin--) {
      string lookup = s.substr(begin, end - begin);
      cerr << "lookup " << lookup << endl;
      if (dict.find(lookup) != dict.end() && wordEnd[begin]) {
        wordEnd[end] = true;
        cerr << "word end at " << end << endl;
        break;
      }
    }
  }
  return wordEnd.back();
}

