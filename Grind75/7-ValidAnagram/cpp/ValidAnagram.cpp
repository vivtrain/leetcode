#include "ValidAnagram.h"
#include <unordered_map>

bool ValidAnagram::isAnagram(std::string s, std::string t) {
  if (s.size() != t.size())
    return false;

  // Construct a map of characters to counts for s
  std::unordered_map<char, size_t> charCounts_s, charCounts_t;
  for (char c : s) {
    std::unordered_map<char, size_t>::iterator foundChar = charCounts_s.find(c);
    if (foundChar == charCounts_s.end()) {
      charCounts_s[c] = 1;
    } else {
      (*foundChar).second++;
    }
  }

  // Construct a map of characters to counts for t
  for (char c : t) {
    std::unordered_map<char, size_t>::iterator foundChar = charCounts_t.find(c);
    if (foundChar == charCounts_t.end()) {
      charCounts_t[c] = 1;
    } else {
      (*foundChar).second++;
    }
  }

  // Compare whether the two maps are equivalent
  if (charCounts_s.size() != charCounts_t.size())
    return false;
  for (auto it_s = charCounts_s.begin(); it_s != charCounts_s.end(); it_s++) {
    auto foundChar = charCounts_t.find((*it_s).first);
    if (foundChar == charCounts_t.end()
        || (*foundChar).second != (*it_s).second)
      return false;
  }
  return true;
}

