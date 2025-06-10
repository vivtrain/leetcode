#include "ProductExceptSelf.h"
#include <vector>
#include <prettyPrint.h>

using namespace std;
 
vector<int> ProductExceptSelf::productExceptSelf(vector<int>& nums) {
  size_t N = nums.size();
  if (N < 2)
    return {};
  vector<int> productsForward(N), productsBackward(N), productsExceptSelf(N);

  productsForward[0] = nums[0];
  productsBackward[N-1] = nums[N-1];
  for (size_t i = 1, j = N-2; i < N && j >= 0; i++, j--) {
    productsForward[i] = productsForward[i-1] * nums[i];
    productsBackward[j] = productsBackward[j+1] * nums[j];
  }

  productsExceptSelf[0] = productsBackward[1];
  productsExceptSelf[N-1] = productsForward[N-2];
  for (size_t i = 1; i < N-1; i++) {
    productsExceptSelf[i] = productsForward[i-1] * productsBackward[i+1];
  }

  return productsExceptSelf;
}
