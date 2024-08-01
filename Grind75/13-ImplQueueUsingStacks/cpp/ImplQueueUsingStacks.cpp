#include "ImplQueueUsingStacks.h"
#include <stack>

MyQueue::MyQueue() {
}

void MyQueue::push(int x) {
  psh_stk.push(x);
}

int MyQueue::pop() {
  if (pop_stk.empty())
    flush_psh();
  int popped = pop_stk.top();
  pop_stk.pop();
  return popped;
}

int MyQueue::peek() {
  if (pop_stk.empty())
    flush_psh();
  return pop_stk.top();
}

bool MyQueue::empty() {
  return psh_stk.empty() && pop_stk.empty();
}

void MyQueue::flush_psh() {
  while (!psh_stk.empty()) {
    int top_psh = psh_stk.top();
    psh_stk.pop();
    pop_stk.push(top_psh);
  }
}
