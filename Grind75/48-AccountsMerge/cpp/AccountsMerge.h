#ifndef ACCOUNTS_MERGE
#define ACCOUNTS_MERGE

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class Solution {
  public:
    std::vector<std::vector<std::string>>
      accountsMerge(std::vector<std::vector<std::string>>& accounts);
    std::vector<std::vector<std::string>>
      accountsMerge2(std::vector<std::vector<std::string>>& accounts);
    std::vector<std::vector<std::string>>
      accountsMerge3(std::vector<std::vector<std::string>>& accounts);
    std::vector<std::vector<std::string>>
      accountsMerge4(std::vector<std::vector<std::string>>& accounts);
  private:
};

class UnionFind {
  public:
    UnionFind(size_t n) : sets(n) {}
    ~UnionFind() { for (Set *s : sets) delete s; }
    struct Set {
      Set(int account=-1)
        : account(account), size(1), rep(this) {}
      int account;
      size_t size;
      Set *rep;
    };
    Set *findRep(Set *element) {
      if (element->rep == element)
        return element;
      Set *rep = findRep(element->rep);
      element->rep = rep;
      return rep;
    }
    void unify(int a, int b) {
      Set *aRep = findRep(sets[a]);
      Set *bRep = findRep(sets[b]);
      if (aRep->size >= bRep->size) {
        bRep->rep = aRep;
        aRep->size += bRep->size;
      } else {
        aRep->rep = bRep;
        bRep->size += aRep->size;
      }
    }
    Set *insert(int account) {
      sets[account] = new Set(account);
      return sets.back();
    }
    std::unordered_map<int, std::vector<int>> groupSets() {
      std::unordered_map<int, std::vector<int>> groups;
      for (auto &set : sets) {
        Set *rep = findRep(set);
        groups[rep->account].push_back(set->account);
      }
      return groups;
    }
  private:
    std::vector<Set*> sets;
};

#endif

