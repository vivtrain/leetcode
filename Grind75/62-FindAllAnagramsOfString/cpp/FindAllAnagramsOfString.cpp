#include "FindAllAnagramsOfString.h"
#include <vector>
#include <string>

using namespace std;

vector<int> Solution::findAnagrams(string s, string p) {
  vector<int> anagrams;
  if (s.empty() || s.size() < p.size())
    return anagrams;

  vector<int> pLetters(26, 0);
  for (char c : p)
    pLetters[c - 'a']++;
  vector<int> sLetters(26, 0);
  for (size_t i = 0; i < p.size(); i++)
    sLetters[s[i] - 'a']++;

  for (size_t end = p.size(); end <= s.size(); end++) {
    size_t start = end - p.size();
    if (sLetters == pLetters)
      anagrams.push_back(start);
    if (end < s.size()) {
      sLetters[s[start] - 'a']--;
      sLetters[s[end] - 'a']++;
    }
  }

  return anagrams;
}

