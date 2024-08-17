#include "AddBinary.h"
#include <string>

std::string AddBinary::addBinary(std::string a, std::string b) {
  size_t maxLength = (a.length() > b.length()) ? a.length()+1 : b.length()+1;
  std::string result(maxLength, '0');

  bool carry = 0;
  for (size_t ia = a.length()-1, ib = b.length()-1, ir = maxLength-1;
       ir < maxLength;
       ia--, ib--, ir--) {
    bool ai = ia >= 0 && a[ia] == '1';
    bool bi = ib >= 0 && b[ib] == '1';
    unsigned short sum = ai + bi + carry;
    carry = sum > 1;
    char si = (sum % 2 == 1) + '0';
    result[ir] = si;
  }

  if (carry)
    result[0] = '1';
  else if (result.length() > 1 && result[0] == '0')
    result.erase(0, 1);
  return result;
}

