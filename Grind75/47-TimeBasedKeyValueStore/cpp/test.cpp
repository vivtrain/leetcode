#include "TimeBasedKeyValueStore.h"
#include <string>
#include <prettyPrint.h>

using namespace std;
using namespace colors;

inline string quote(string s) { return '"' + s + '"'; }

int main() {
  TimeMap tm;
  string s;
  s = tm.get("key", 1);
  colorOut(s == "" ? GREEN : RED, quote(s)) << endl;
  tm.set("key", "LOW", 2);
  tm.set("key", "HIGH", 4);
  s = tm.get("key", 1);
  colorOut(s == "" ? GREEN : RED, quote(s)) << endl;
  s = tm.get("key", 2);
  colorOut(s == "LOW" ? GREEN : RED, quote(s)) << endl;
  s = tm.get("key", 3);
  colorOut(s == "LOW" ? GREEN : RED, quote(s)) << endl;
  s = tm.get("key", 4);
  colorOut(s == "HIGH" ? GREEN : RED, quote(s)) << endl;
  s = tm.get("key", 5);
  colorOut(s == "HIGH" ? GREEN : RED, quote(s)) << endl;
}

