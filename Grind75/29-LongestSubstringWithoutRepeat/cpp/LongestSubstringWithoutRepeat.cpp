#include "LongestSubstringWithoutRepeat.h"
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

int LongestSubstringWithoutRepeat::lengthOfLongestSubstring(std::string s) {
  int count = 0, max = 0;
  size_t start = 0;
  unordered_map<char, size_t> seen;
  for (size_t i = 0; i < s.size(); i++) {
    auto loc = seen.find(s[i]);
    if (loc != seen.end() && loc->second >= start) {
      start = loc->second + 1;
      count = i - start + 1;
      loc->second = i;
    } else {
      count++;
      seen[s[i]] = i;
    }
    if (count > max)
      max = count;
  }
  return max;
}

