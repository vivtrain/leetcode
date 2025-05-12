#include <colors.h>
#include <ostream>
#include <prettyPrint.h>
#include <vector>
#include <iostream>

int main() {
  std::vector<int> vec;
  std::vector<std::vector<int>> vec2D;

  prettyPrint(vec);
  std::cout << prettyString(vec) << std::endl;
  prettyPrint2D(vec2D);
  vec.push_back(1);
  vec2D.push_back(vec);
  std::cout << std::endl;

  prettyPrint(vec);
  std::cout << prettyString(vec) << std::endl;
  prettyPrint2D(vec2D);
  vec.push_back(2);
  vec2D.push_back(vec);
  std::cout << std::endl;

  prettyPrint(vec);
  std::cout << prettyString(vec) << std::endl;
  prettyPrint2D(vec2D);
  vec.push_back(3);
  vec2D.push_back(vec);
  std::cout << std::endl;

  prettyPrint(vec);
  std::cout << prettyString(vec) << std::endl;
  colorOut(colors::BLUE)<< prettyString(vec) << std::endl;
  prettyPrint2D(vec2D);
}

