#include "RansomNote.h"
#include <string>
#include <unordered_map>
#include <vector>

bool RansomNote::canConstruct(std::string ransomNote, std::string magazine) {
  std::unordered_map<char, size_t> magLetters, noteLetters;

  for (char c : ransomNote)
    noteLetters[c]++;
  for (char c : magazine)
    magLetters[c]++;

  for (std::pair<char, size_t> letterCount : noteLetters) {
    auto found = magLetters.find(letterCount.first);
    if (found == magLetters.end())
      return false;
    else if (found->second < letterCount.second)
      return false;
  }

  return true;
}

bool RansomNote::canConstruct2(std::string ransomNote, std::string magazine) {
  std::unordered_map<char, int> magLetters;
  for (char c : magazine)
    magLetters[c]++;
  for (char c : ransomNote) {
    int count = --magLetters[c];
    if (count < 0)
      return false;
  }
  return true;
}

bool RansomNote::canConstruct3(std::string ransomNote, std::string magazine) {
  std::vector<int> magLetters(26);
  for (char c : magazine)
    magLetters[c - 'a']++;
  for (char c : ransomNote) {
    if (--magLetters[c - 'a'] < 0)
      return false;
  }
  return true;
}


