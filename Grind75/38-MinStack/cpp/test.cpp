#include "MinStack.h"
#include <cassert>

int main() {
  MinStack2 ms;
  ms.push(1);
  assert(ms.top()    == 1);
  assert(ms.getMin() == 1);
  ms.push(2);
  assert(ms.top()    == 2);
  assert(ms.getMin() == 1);
  ms.push(0);
  assert(ms.top()    == 0);
  assert(ms.getMin() == 0);
  ms.pop();
  assert(ms.top()    == 2);
  assert(ms.getMin() == 1);
}

