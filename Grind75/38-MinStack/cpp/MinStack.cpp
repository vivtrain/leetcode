#include "MinStack.h"
#include <stack>
#include <utility>

using namespace std;

void MinStack::push(int val) {
  if (stack.empty())
    stack.push(make_pair(val, val));
  else
    stack.push(make_pair(val, min(getMin(), val)));
}

void MinStack::pop() {
  stack.pop();
}

int MinStack::top() {
  return stack.top().first;
}

int MinStack::getMin() {
  return stack.top().second;
}


void MinStack2::push(int val) {
  Node *newTop;
  if (!topNode)
    newTop = new Node(val, val, nullptr);
  else
    newTop = new Node(val, min(topNode->min, val), topNode);
  topNode = newTop;
}

void MinStack2::pop() {
  Node *toPop = topNode;
  topNode = topNode->below;
  delete toPop;
}

int MinStack2::top() {
  return topNode->value;
}

int MinStack2::getMin() {
  return topNode->min;
}

