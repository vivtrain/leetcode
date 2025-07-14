#ifndef LRU_CACHE
#define LRU_CACHE

#include <sys/types.h>
#include <unordered_map>
#include <utility>
#include <vector>

class LRUCache {
  public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
    void print();
  private:
    struct Node {
      Node(int key=-1, int value=0, Node *next=nullptr, Node *prev=nullptr)
        : key(key), value(value), next(next), prev(prev) {}
      const int key;
      int value;
      Node *next;
      Node *prev;
    };
    std::unordered_map<int, Node*> keyToLoc;
    uint capacity;
    uint size = 0;
    Node *MRU = nullptr; // head
    Node *LRU = nullptr; // tail
    void insert(int key, int value);
    void update(Node *const node, int value);
};

#endif

