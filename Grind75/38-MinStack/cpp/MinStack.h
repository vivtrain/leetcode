#ifndef MIN_STACK
#define MIN_STACK

#include <stack>
#include <utility>

class MinStack {
  public:
    MinStack() {}
    void push(int val);
    void pop();
    int top();
    int getMin();
  private:
    std::stack<std::pair<int, int>> stack;
};

class MinStack2 {
  public:
    MinStack2() : topNode(nullptr) {}
    ~MinStack2() { while(topNode) pop(); }
    void push(int val);
    void pop();
    int top();
    int getMin();
  private:
    struct Node {
      Node(int value, int min, Node *below) :
        value(value), min(min), below(below) {}
      int value;
      int min;
      Node *below;
    };
    Node *topNode;
};

#endif

