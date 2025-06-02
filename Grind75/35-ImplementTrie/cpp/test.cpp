#include "ImplementTrie.h"
#include <cassert>

int main() {
  Trie trie;
  trie.insert("a");
  assert(!trie.search(""));
  assert(!trie.search("b"));
  assert(!trie.search("ab"));
  assert(trie.search("a"));
  assert(trie.startsWith(""));
  assert(trie.startsWith("a"));
  assert(!trie.startsWith("ab"));
  assert(!trie.startsWith("b"));
  trie.insert("apple");
  assert(trie.startsWith("app"));
}

