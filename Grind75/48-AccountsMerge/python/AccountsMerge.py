#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')
from typing import DefaultDict, Dict, List, Set
from collections import defaultdict
from PrettyPrint import *

class UnionFind:
  def __init__(self, nElements: int) -> None:
    self.reps: List[int] = list(range(nElements))

  def findRep(self, element: int) -> int:
    e = self.reps[element]
    if e == element:
      return element
    rep = self.findRep(e)
    self.reps[element] = rep
    return rep

  def unify(self, e1: int, e2: int):
    rep1 = self.findRep(e1)
    rep2 = self.findRep(e2)
    self.reps[rep1] = rep2

  def groupSets(self) -> DefaultDict[int, List[int]]:
    groups: DefaultDict[int, List[int]] = defaultdict(list)
    for i,r in enumerate(self.reps):
      groups[self.findRep(r)].append(i)
    return groups


class Solution:
  def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
    emailAccountId: Dict[str, int] = {}
    uf = UnionFind(len(accounts))
    for id, merged in enumerate(accounts):
      for email in merged[1:]:
        if email in emailAccountId:
          uf.unify(id, emailAccountId[email])
        else:
          emailAccountId[email] = id
    groups = uf.groupSets()
    results: List[List[str]] = []
    for rep, ids in groups.items():
      merged: List[str] = [ accounts[rep][0] ]
      cleanedUp = []
      for id in ids:
        cleanedUp.extend(accounts[id][1:])
      cleanedUp = sorted(list(set(cleanedUp)))
      merged.extend(cleanedUp)
      results.append(merged)
    return results

if __name__ == '__main__':
  soln = Solution()
  accounts: List[List[str]] = [
    ["Dave","Dave0@m.co","Dave5@m.co","Dave0@m.co"],
    ["Lily","Lily4@m.co","Lily2@m.co","Lily0@m.co"],
    ["Fern","Fern5@m.co","Fern2@m.co","Fern6@m.co"],
    ["Gabe","Gabe0@m.co","Gabe6@m.co","Gabe8@m.co"],
    ["Alex","Alex7@m.co","Alex5@m.co","Alex7@m.co"],
    ["Lily","Lily4@m.co","Lily6@m.co","Lily7@m.co"],
    ["Alex","Alex0@m.co","Alex4@m.co","Alex5@m.co"],
    ["John","John4@m.co","John2@m.co","John0@m.co"],
  ]
  prettyPrint2D(soln.accountsMerge(accounts))
