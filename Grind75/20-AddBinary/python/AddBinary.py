#!/bin/python3

from __future__ import annotations
import sys
sys.path.append('../../Utility/python')

class Solution(object):
  def addBinary(self, a: str, b: str) -> str:
    sLen = max(len(a), len(b)) + 1
    s = ['0' for i in range(sLen)]
    i_a, i_b, i_s = len(a)-1, len(b)-1, sLen-1
    c_i = 0
    while i_s >= 0:
      a_i = int(a[i_a]) if i_a >= 0 else 0
      b_i = int(b[i_b]) if i_b >= 0 else 0
      s_i = a_i + b_i + c_i
      c_i = int(s_i >= 2)
      s[i_s] = str(int(s_i % 2 == 1))
      i_a -= 1
      i_b -= 1
      i_s -= 1
    if c_i == 1:
      s[0] = '1'
    if s[0] == '0' and sLen > 1:
      s.pop(0)
    return ''.join(s)

  def addBinary2(self, a: str, b: str) -> str:
    a = a if not a == '' else '0'
    b = b if not b == '' else '0'
    return bin((int(a,2) + int(b,2)))[2:]

if __name__ == '__main__':
  soln = Solution()
  testCases = [
      ('', '', '0'),
      ('0', '', '0'),
      ('', '0', '0'),
      ('0', '0', '0'),
      ('0', '1', '1'),
      ('1', '0', '1'),
      ('1', '1', '10'),
      ('1', '10', '11'),
      ('10', '1', '11'),
      ('10', '10', '100'),
      ('11', '11', '110'),
      ('1111', '1', '10000'),
      ('1010', '1011', '10101'),
      ]


  for test in testCases:
    print(f'{test[0]} + {test[1]} = {test[2]} -> ', end='')
    result = soln.addBinary2(test[0], test[1])
    print(result)
    assert result == test[2]
  print('TESTS PASSED!')

