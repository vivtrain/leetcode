#include "LRUCache.h"
#include "colors.h"
#include <prettyPrint.h>

using namespace std;
using namespace colors;

int main() {
  LRUCache cache(2);
  int result;
  cache.print();

  colorOut(LIGHT_BLUE, "Put 1 -> 1") << endl;
  cache.put(1, 1);
  cache.print();

  colorOut(LIGHT_BLUE, "Put 2 -> 2") << endl;
  cache.put(2, 2);
  cache.print();

  colorOut(LIGHT_BLUE, "Get 1 -> 1") << endl;
  result = cache.get(1);
  cout << " --> ";
  colorOut(result == 1 ? GREEN : RED, result) << endl;
  cache.print();

  colorOut(LIGHT_BLUE, "Put 3 -> 3") << endl;
  cache.put(3, 3);
  cache.print();

  colorOut(LIGHT_BLUE, "Get 2 -> 2") << endl;
  result = cache.get(2);
  cout << " --> ";
  colorOut(result == -1 ? GREEN : RED, result) << endl;
  cache.print();

  colorOut(LIGHT_BLUE, "Put 4 -> 4") << endl;
  cache.put(4, 4);
  cache.print();

  colorOut(LIGHT_BLUE, "Get 1 -> 1") << endl;
  result = cache.get(1);
  cout << " --> ";
  colorOut(result == -1 ? GREEN : RED, result) << endl;
  cache.print();

  colorOut(LIGHT_BLUE, "Get 3 -> 3") << endl;
  result = cache.get(3);
  cout << " --> ";
  colorOut(result == 3 ? GREEN : RED, result) << endl;
  cache.print();

  colorOut(LIGHT_BLUE, "Get 4 -> 4") << endl;
  result = cache.get(4);
  cout << " --> ";
  colorOut(result == 4 ? GREEN : RED, result) << endl;
  cache.print();
}

