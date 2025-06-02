#ifndef IMPLEMENT_TRIE
#define IMPLEMENT_TRIE

#include <string>

class Trie {
  public:
    char value;
    Trie *&nextCh(char ch) { return next[int(ch - 'a')]; }
    Trie(char value='\0') : value(value), next(), endOfWord(false) {}
    void insert(std::string word);
    bool search(std::string word);
    bool startsWith(std::string prefix);
  private:
    Trie *next[26];
    bool endOfWord;
};

#endif

