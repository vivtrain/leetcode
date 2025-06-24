#include "AccountsMerge.h"
#include "prettyPrint.h"
#include <algorithm>
#include <cstddef>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int findRep(const int &element, unordered_map<int, int> &reps) {
  if (reps.find(element) == reps.end())
    reps[element] = element;
  int r = reps[element];
  while (r != reps[r])
    r = reps[r];
  reps[element] = r;
  return r;
}

void unify(const int &e1, const int &e2, unordered_map<int, int> &reps) {
  reps[findRep(e2, reps)] = findRep(e1, reps);
}

vector<vector<string>> Solution::accountsMerge3(vector<vector<string>> &accounts) {
  unordered_map<int, int> reps;
  unordered_map<string, int> seen;
  for (size_t a = 0; a < accounts.size(); a++) {
    const vector<string> &account = accounts[a];
    for (size_t e = 1; e < account.size(); e++) {
      int toUnify = a;
      if (seen.find(account[e]) != seen.end())
        toUnify = seen[account[e]];
      seen[account[e]] = a;
      unify(toUnify, a, reps);
    }
  }
  vector<vector<string>> results(accounts.size());
  for (auto &[set, rep] : reps) {
    vector<string> &result = results[findRep(rep, reps)];
    int offset = 1;
    if (result.empty())
      offset = 0;
    result.insert(result.end(), accounts[set].begin()+offset, accounts[set].end());
  }
  auto removeEmpty = remove_if(results.begin(), results.end(),
      [](const auto &v) {return v.empty();});
  results.erase(removeEmpty, results.end());
  for (auto &r : results) {
    sort(r.begin()+1, r.end());
    auto last = unique(r.begin()+1, r.end());
    r.erase(last, r.end());
  }
  return results;
}

string findRep(const string &element, unordered_map<string, string> &reps) {
  if (reps.find(element) == reps.end())
    reps[element] = element;
  string r = reps[element];
  while (r != reps[r])
    r = reps[r];
  reps[element] = r;
  return r;
}

void unify(const string &e1, const string &e2, unordered_map<string, string> &reps) {
  reps[findRep(e2, reps)] = findRep(e1, reps);
}

vector<vector<string>> Solution::accountsMerge(vector<vector<string>> &accounts) {
  unordered_map<string, string> reps;
  unordered_map<string, set<string>> recoverSets;
  unordered_map<string, const string*> names;
  for (size_t a = 0; a < accounts.size(); a++) {
    const vector<string> &account = accounts[a];
    for (size_t e = 1; e < account.size(); e++) {
      unify(account[1], account[e], reps);
      names[account[e]] = &account[0];
    }
  }
  vector<vector<string>> result;
  for (auto &[email, rep] : reps)
    recoverSets[findRep(rep, reps)].insert(email);
  for (auto &[rep, set] : recoverSets) {
    vector<string> s({*names[*set.begin()]});
    s.insert(s.end(), set.begin(), set.end());
    result.emplace_back(s);
  }
  // sort(result.begin(), result.end(), [](auto &a, auto &b) {return a[0]<b[0];});
  return result;
}

vector<vector<string>> Solution::accountsMerge2(vector<vector<string>>& accounts) {
  multimap<string, set<string>> acctMap;
  for (vector<string> &acct : accounts) {
    string name = acct[0];
    set<string> emails;
    emails.insert(acct.begin()+1, acct.end());
    auto [found, foundEnd] = acctMap.equal_range(name);
    while (found != acctMap.end() && found->first == name) {
      bool merged = false;
      for (string email : emails) {
        if (found->second.find(email) != found->second.end()) {
          emails.merge(found->second);
          merged = true;
          break;
        }
      }
      merged ? found = acctMap.erase(found) : found++;
    }
    acctMap.emplace(make_pair(name, emails));
  }
  vector<vector<string>> result;
  for (auto it = acctMap.begin(); it != acctMap.end(); it++) {
    vector<string> a;
    a.push_back(it->first);
    a.insert(a.end(), it->second.begin(), it->second.end());
    result.emplace_back(a);
  }
  return result;
}
