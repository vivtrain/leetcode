#include "ValidPalindrome.h"

bool ValidPalindrome::isPalindrome(std::string s) {
  if (s.empty())
    return true;
  size_t forward = 0, backward = s.size()-1;
  
  while (forward < backward) {
    while (!std::isalnum(s[forward]) && forward < backward)
      forward++;
    while (!std::isalnum(s[backward]) && forward < backward)
      backward--;
    if (forward >= backward)
      return true;
    if (std::tolower(s[forward]) != std::tolower(s[backward]))
      return false;
    forward++;
    backward--;
  }
  return true;
}

bool ValidPalindrome::isPalindrome_it(std::string s) {
  if (s.empty())
    return true;
  std::string::const_iterator forward = s.cbegin();
  std::string::const_iterator backward = s.cend()-1;

  while (forward < backward) {
    while (!std::isalnum(*forward) && forward < backward)
      forward++;
    while (!std::isalnum(*backward) && forward < backward)
      backward--;
    if (forward >= backward)
      return true;
    if (std::tolower(*forward) != std::tolower(*backward))
      return false;
    forward++;
    backward--;
  }
  return true;
}

