#include "StringToInteger.h"
#include <cctype>
#include <cstdint>
#include <string>

using namespace std;

int Solution::myAtoi(string s) {
  long magnitude = 0;
  int sign = 1;
  size_t i = 0;
  // Trim leading whitespace
  while (i < s.size() && s[i] == ' ') i++;
  if (i == s.size()) return 0;
  // Determine sign if any
  if (s[i] == '-') {
    sign = -1;
    i++;
  } else if (s[i] == '+') i++;
  // Convert to number
  for (; i < s.size() && isdigit(s[i]); i++) {
    magnitude = magnitude * 10 + (s[i]-'0');
    if      (sign * magnitude > INT32_MAX) return INT32_MAX;
    else if (sign * magnitude < INT32_MIN) return INT32_MIN;
  }
  return sign * magnitude;
}

int Solution::myAtoi2(string s) {
  string digits;
  size_t i = 0;
  // Leading whitespace
  while (i < s.size() && s[i] == ' ') i++;
  if (i == s.size()) return 0;
  // Sign
  int sign;
  if (s[i] == '-') {
    sign = -1;
    i++;
  } else if (s[i] == '+' || isdigit(s[i])) {
    sign = 1;
    if (s[i] == '+') i++;
  } else {
    return 0;
  }
  if (i == s.size()) return 0;
  // Store digits
  bool leadingZeros = true;
  while (i < s.size() && isdigit(s[i])) {
    if (s[i] != '0')
      leadingZeros = false;
    if (!leadingZeros)
      digits.push_back(s[i]);
    i++;
  }
  if (digits.size() > 10)
    return sign == 1 ? INT32_MAX : INT32_MIN;
  // Convert to int
  size_t output = 0, place = 1;
  for (int c = digits.size()-1; c >= 0; c--) {
    output += (digits[c]-'0') * place;
    place *= 10;
    if (output > INT32_MAX)
      return sign == 1 ? INT32_MAX : INT32_MIN;
  }
  return output * sign;
}

