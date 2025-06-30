#include <colors.h>
#include <map>
#include <ostream>
#include <prettyPrint.h>
#include <vector>
#include <iostream>

using namespace std;

void main2() {
  vector<int> vec;
  vector<vector<int>> vec2D;

  prettyPrint(vec);
  cout << prettyString(vec) << endl;
  prettyPrint2D(vec2D);
  vec.push_back(1);
  vec2D.push_back(vec);
  cout << endl;

  prettyPrint(vec);
  cout << prettyString(vec) << endl;
  prettyPrint2D(vec2D);
  vec.push_back(2);
  vec2D.push_back(vec);
  cout << endl;

  prettyPrint(vec);
  cout << prettyString(vec) << endl;
  prettyPrint2D(vec2D);
  vec.push_back(3);
  vec2D.push_back(vec);
  cout << endl;

  prettyPrint(vec);
  cout << prettyString(vec) << endl;
  colorOut(colors::BLUE, prettyString(vec)) << endl;
  prettyPrint2D(vec2D);
}

int main() {
  main2();
  map<int, string> m;
  unordered_map<string, int> um;
  set<int> s;
  unordered_set<string> us;
  prettyPrint(m);
  prettyPrint(um);
  prettyPrint(s);
  prettyPrint(us);
  m[1] = "m1";
  um["um1"] = 1;
  s.insert(1);
  us.insert("s1");
  prettyPrint(m);
  prettyPrint(um);
  prettyPrint(s);
  prettyPrint(us);
  m[2] = "m2";
  um["um2"] = 2;
  s.insert(2);
  us.insert("s2");
  prettyPrint(m);
  prettyPrint(um);
  prettyPrint(s);
  prettyPrint(us);
  colorOut(colors::LIGHT_CYAN, prettyString(m)) << endl;
  colorOut(colors::LIGHT_BLUE, prettyString(um, ",", ":")) << endl;
  colorOut(colors::LIGHT_GREEN, prettyString(s)) << endl;
  colorOut(colors::LIGHT_PURPLE, prettyString(us, " ")) << endl;
}
