#include "EvaluateReversePolish.h"
#include <vector>
#include <string>
#include <stack>

using namespace std;

int EvaluateReversePolish::evalRPN(vector<string>& tokens) {
  stack<int> stack;

  for (string token : tokens) {
    if (token == "+") {
      int n2 = stack.top();
      stack.pop();
      int n1 = stack.top();
      stack.pop();
      stack.push(n1 + n2);
    } else if (token == "-") {
      int n2 = stack.top();
      stack.pop();
      int n1 = stack.top();
      stack.pop();
      stack.push(n1 - n2);
    } else if (token == "*") {
      int n2 = stack.top();
      stack.pop();
      int n1 = stack.top();
      stack.pop();
      stack.push(n1 * n2);
    } else if (token == "/") {
      int n2 = stack.top();
      stack.pop();
      int n1 = stack.top();
      stack.pop();
      stack.push(n1 / n2);
    } else {
      stack.push(stoi(token));
    }
  }

  return stack.top();
}

