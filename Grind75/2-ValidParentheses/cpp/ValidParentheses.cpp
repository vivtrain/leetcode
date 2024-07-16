#include "ValidParentheses.h"
#include <string>
#include <stack>

bool ValidParentheses::isValid(std::string s) {
  std::stack<char> stk;
  for (char c : s) {
    switch (c) {
      case '(':
      case '[':
      case '{':
        stk.push(c);
        break;
      case ')':
        if (!stk.empty() && stk.top() == '(')
          stk.pop();
        else
          return false;
        break;
      case ']':
        if (!stk.empty() && stk.top() == '[')
          stk.pop();
        else
          return false;
        break;
      case '}':
        if (!stk.empty() && stk.top() == '{')
          stk.pop();
        else
          return false;
        break;
    }
  }
  return stk.empty();
}

