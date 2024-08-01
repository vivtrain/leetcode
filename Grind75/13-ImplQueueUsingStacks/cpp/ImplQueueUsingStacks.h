#ifndef IMPL_QUEUE_USING_STACKS
#define IMPL_QUEUE_USING_STACKS

#include <stack>

class MyQueue {
  public:
    MyQueue();
    void push(int x);
    int pop();
    int peek();
    bool empty();
  private:
    void flush_psh();
    std::stack<int> psh_stk;
    std::stack<int> pop_stk;
};

#endif

