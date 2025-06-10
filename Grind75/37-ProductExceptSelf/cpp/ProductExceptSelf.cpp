#include "ProductExceptSelf.h"
#include <vector>
#include <prettyPrint.h>

using namespace std;
 
vector<int> ProductExceptSelf::productExceptSelf_ONsp(vector<int>& nums) {
  int N = nums.size();
  if (N < 2)
    return {};
  vector<int> productsForward(N), productsBackward(N), productsExceptSelf(N);

  productsForward[0] = productsBackward[N-1] = 1;
  for (int i = 1, j = N-2; i < N && j >= 0; i++, j--) {
    productsForward[i] = productsForward[i-1] * nums[i-1];
    productsBackward[j] = productsBackward[j+1] * nums[j+1];
  }

  for (int i = 0; i < N; i++)
    productsExceptSelf[i] = productsForward[i] * productsBackward[i];

  return productsExceptSelf;
}

vector<int> ProductExceptSelf::productExceptSelf(vector<int>& nums) {
  int N = nums.size();
  if (N < 2)
    return {};
  vector<int> productsExceptSelf(N);

  productsExceptSelf[0] = 1;
  for (int i = 1; i < N; i++)
    productsExceptSelf[i] = productsExceptSelf[i-1] * nums[i-1];
  int productsBackward = 1;
  for (int j = N-1; j >= 0; j--) {
    productsExceptSelf[j] *= productsBackward;
    productsBackward *= nums[j];
  }

  return productsExceptSelf;
}
