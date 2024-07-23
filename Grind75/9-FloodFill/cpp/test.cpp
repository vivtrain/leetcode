#include "FloodFill.h"
#include <iostream>
#include "../../Utility/prettyPrint.h"
#include <cassert>
#include <vector>
#include <tuple>

using Image = std::vector<std::vector<int>>;

void prettyPrintImage(const Image &image) {
  for (std::vector<int> row : image)
    prettyPrint(row);
}

int main() {
  FloodFill soln;
  std::vector<std::tuple<Image, int, int, int, Image>> testCases;
  Image empty = Image{{}};
  Image img1 = Image{{1}};
  Image img0 = Image{{0}};
  Image square = Image{{1,1,1},{1,1,0},{1,0,1}};
  Image rect = Image{{1,1,2},{1,0,1}};
  assert(empty == empty);
  assert(img1 == img1);
  assert(square == square);
  assert(rect == rect);
  assert(empty != img0);
  assert(img1 != img0);
  assert(square != rect);

  testCases.push_back(std::make_tuple(empty, 0, 0, 0, empty));
  testCases.push_back(std::make_tuple(img1, 1, 0, 0, img1));
  testCases.push_back(std::make_tuple(img1, 0, 1, 0, img1));
  testCases.push_back(std::make_tuple(img1, -1, 0, 0, img1));
  testCases.push_back(std::make_tuple(img1, 0, -1, 0, img1));
  testCases.push_back(std::make_tuple(img1, 0, 0, 0, img0));
  testCases.push_back(std::make_tuple(square, 1, 1, 2,
        Image{{2,2,2},{2,2,0},{2,0,1}}));
  testCases.push_back(std::make_tuple(rect, 0, 0, 2,
        Image{{2,2,2},{2,0,1}}));

  for (auto test : testCases) {
    Image testImg = std::get<0>(test);
    int row = std::get<1>(test);
    int col = std::get<2>(test);
    int color = std::get<3>(test);
    Image correctResult = std::get<4>(test);
    prettyPrintImage(testImg);
    std::cout << "(" << row << ", " << col << ")"
        << " -> " << color << std::endl;
    std::cout << "Expected: " << std::endl;
    prettyPrintImage(correctResult);
    std::cout << "Yield: " << std::endl;
    Image result = soln.floodFill(testImg, row, col, color);
    prettyPrintImage(result);
    assert(result == correctResult);
    std::cout << "------------------ PASSED ------------------\n\n";
  }
}

