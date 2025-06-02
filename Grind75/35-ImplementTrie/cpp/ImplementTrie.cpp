#include "ImplementTrie.h"

void Trie::insert(std::string word) {
  Trie *node = this;
  for (char c : word) {
    if (!node->nextCh(c))
      node->nextCh(c) = new Trie(c);
    node = node->nextCh(c);
  }
  node->endOfWord = true;
}

bool Trie::search(std::string word) {
  Trie *node = this;
  for (char c : word) {
    if (!node->nextCh(c))
      return false;
    node = node->nextCh(c);
  }
  return node->endOfWord;
}

bool Trie::startsWith(std::string prefix) {
  Trie *node = this;
  for (char c : prefix) {
    if (!node->nextCh(c))
      return false;
    node = node->nextCh(c);
  }
  return true;
}

