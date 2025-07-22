#include "BasicCalculator.h"
#include <string>

using namespace std;

int calc(const string &s, uint &i) {
  int result = 0;
  int num = 0;
  int sign = 1;
  while (i < s.size() && s[i] != ')') {
    if (isdigit(s[i])) {
      num *= 10;
      num += int(s[i] - '0');
    } else {
      if (s[i] == '(') {
        num = calc(s, ++i);
        result += sign * num;
        sign = 1;
        num = 0;
      } else if (s[i] == '+') {
        result += sign * num;
        sign = 1;
        num = 0;
      } else if (s[i] == '-') {
        result += sign * num;
        sign = -1;
        num = 0;
      }
    }
    i++;
  }
  result += sign * num;
  return result;
}

int Solution::calculate(string s) {
  uint index = 0;
  return calc(s, index);
}

