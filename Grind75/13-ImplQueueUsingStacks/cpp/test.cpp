#include "ImplQueueUsingStacks.h"
#include <iostream>
#include <cassert>

int main() {
  MyQueue* q = new MyQueue();
  assert(q->empty());
  q->push(1);
  assert(!q->empty());
  q->push(2);
  assert(q->pop() == 1);
  assert(q->pop() == 2);
  assert(q->empty());
  q->push(3);
  assert(q->peek() == 3);
  assert(q->pop() == 3);
  assert(q->empty());
  std::cout << "TEST PASSED!" << std::endl;
}

