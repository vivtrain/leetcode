#include "LRUCache.h"
#include "colors.h"
#include <iostream>

using namespace std;

LRUCache::LRUCache(int capacity) : keyToLoc(), capacity(capacity) {}

int LRUCache::get(int key) {
  auto found = keyToLoc.find(key);
  if (found == keyToLoc.end())
    return -1;
  Node *const node = found->second;
  update(node, node->value);
  return node->value;
}

void LRUCache::insert(int key, int value) {
  Node *const newNode = new Node(key, value);
  if (size == capacity) {
    // Evict from LRU side
    keyToLoc.erase(LRU->key);
    if (LRU->prev) {
      LRU = LRU->prev;
      delete LRU->next;
      LRU->next = nullptr;
    } else { // i.e. LRU == MRU
      delete LRU;
      LRU = nullptr;
      MRU = nullptr;
    }
    size--;
  }
  // Insert at MRU side
  newNode->next = MRU;
  if (MRU)
    MRU->prev = newNode;
  else
    LRU = newNode;
  MRU = newNode;
  keyToLoc[key] = newNode;
  size++;
}

void LRUCache::update(Node *const node, int value) {
  node->value = value;
  Node *const prev = node->prev, *const next = node->next;
  if (node == MRU) {
    // No change needed
    return;
  } else if (node == LRU) {
    // Unlink tail node, update new LRU
    prev->next = nullptr;
    LRU = prev;
  } else {
    // Unlink middle node
    next->prev = prev;
    prev->next = next;
  }
  // Make node MRU
  node->next = MRU;
  node->prev = nullptr;
  MRU->prev = node;
  MRU = node;
}

void LRUCache::put(int key, int value) {
  auto found = keyToLoc.find(key);
  if (found == keyToLoc.end())
    insert(key, value);
  else
    update(found->second, value);
}

void LRUCache::print() {
  Node *node = MRU;
  cout << "[MRU] <-> ";
  while (node) {
    if (node == MRU && node == LRU)
      cout << colors::GREEN;
    else if (node == MRU)
      cout << colors::LIGHT_CYAN;
    else if (node == LRU)
      cout << colors::LIGHT_YELLOW;
    cout << "(k:" << node->key << ", v:" << node->value << ")";
    cout << colors::NO_COLOR << " <-> ";
    node = node->next;
  }
  cout << "[LRU]" << endl;
  // node = LRU;
  // cout << "[LRU] <-> ";
  // while (node) {
  //   if (node == MRU && node == LRU)
  //     cout << colors::GREEN;
  //   else if (node == MRU)
  //     cout << colors::LIGHT_CYAN;
  //   else if (node == LRU)
  //     cout << colors::LIGHT_YELLOW;
  //   cout << "(k:" << node->key << ", v:" << node->value << ")";
  //   cout << colors::NO_COLOR << " <-> ";
  //   node = node->prev;
  // }
  // cout << "[MRU]" << endl;
}

