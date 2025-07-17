#include "MinimumWindowSubstring.h"
#include "prettyPrint.h"
#include <cassert>
#include <optional>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class MinWindow {
  public:
    MinWindow(size_t sSize, const unordered_map<char, uint> &freqs)
        : maxSize(0), selected(sSize) {
      for (const auto &[ch, count] : freqs) {
        locs[ch].second = count;
        maxSize += count;
      }
    }
    MinWindow() = delete;
    MinWindow(const MinWindow &_) = delete;
    MinWindow(MinWindow &&_) = delete;

    void update(char c, uint loc) {
      // cout << "before update: ";
      // prettyPrint(selected);
      // prettyPrint(vector<uint>{minLoc, maxLoc});
      assert(locs.find(c) != locs.end());
      auto &[q, max] = locs[c];
      if (q.size() == max) {
        uint locToPop = q.front();
        if (locToPop == minLoc && size > 1) {
          uint newMin = minLoc + 1;
          while (!selected[newMin] && newMin < selected.size())
            newMin++;
          minLoc = newMin;
        }
        selected[locToPop] = false;
        q.pop();
        size--;
      }
      q.push(loc);
      if (size == 0)
        minLoc = loc;
      selected[loc] = true;
      maxLoc = loc;
      size++;
      // cout << "after update: ";
      // prettyPrint(selected);
      // prettyPrint(vector<uint>{minLoc, maxLoc});
    }

    inline constexpr optional<pair<uint, uint>> getWindow() {
      if (size == maxSize)
        return pair{minLoc, maxLoc};
      else
        return nullopt;
    }

  private:
    uint size = 0;
    uint maxSize;
    vector<bool> selected;
    unordered_map<char, pair<queue<uint>, uint>> locs;
    uint minLoc = 0;
    uint maxLoc = 0;
};

inline bool smallerWin(
    const optional<pair<uint, uint>> &a,
    const optional<pair<uint, uint>> &b) {
  if (a.has_value() && b.has_value()
      && a->second - a->first + 1 < b->second - b->first + 1)
    return true;
  else
    return false;
}

string Solution::minWindow2(string s, string t) {
  unordered_map<char, uint> sFreqs, tFreqs;
  for (const char c : t)
    tFreqs[c]++;

  MinWindow mw(s.size(), tFreqs);
  optional<pair<uint, uint>> bestWin(nullopt);
  optional<pair<uint, uint>> win(nullopt);

  for (uint c = 0; c < s.size(); c++) {
    const char ch = s[c];
    if (tFreqs.find(ch) == tFreqs.end())
      continue;
    mw.update(ch, c);
    win = mw.getWindow();
    if ((!bestWin.has_value() && win.has_value()) || smallerWin(win, bestWin))
      bestWin = win;
  }

  if (bestWin.has_value())
    return s.substr(bestWin->first, bestWin->second - bestWin->first + 1);
  else
    return "";
}

int toIndex(char c) {
  if ('a' <= c && c <= 'z')
    return c - 'a';
  else if ('A' <= c && c <= 'Z')
    return c - 'A' + 26;
  else
    return -1;
}

string Solution::minWindow(string s, string t) {
  string answer = "";
  if (s.empty() || t.size() > s.size())
    return answer;
  vector<int> need(52, 0), have(52, 0);
  uint nNeeded = 0;
  uint nSatisfied = 0;
  for (const char &c : t) {
    if (need[toIndex(c)] == 0)
      nNeeded++;
    need[toIndex(c)]++;
  }
  int bestStart = -1, bestEnd = -1;
  int start = -1;

  for (int end = 1; uint(end) <= s.size(); end++) {
    const char &chEnd = s[end-1];
    if (need[toIndex(chEnd)] == 0)
      continue;
    have[toIndex(chEnd)]++;
    if (start == -1)
      start = end - 1;
    if (have[toIndex(chEnd)] == need[toIndex(chEnd)])
      nSatisfied++;
    if (nSatisfied == nNeeded) {
      for (int st = start; st < end; st++) {
        const char &chSt = s[st];
        if (need[toIndex(chSt)] == 0)
          continue;
        start = st;
        if (have[toIndex(chSt)] == need[toIndex(chSt)])
          break;
        have[toIndex(chSt)]--;
      }
      if (bestStart == -1 || end - start < bestEnd - bestStart) {
        bestStart = start;
        bestEnd = end;
      }
    }
  }

  if (bestStart != -1)
    return s.substr(bestStart, bestEnd - bestStart);
  else 
    return "";
}

