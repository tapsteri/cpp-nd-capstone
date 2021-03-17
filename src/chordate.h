#ifndef CHORDATE_H
#define CHORDATE_H

#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include "SDL.h"
#include "random_generator.h"

class Chordate {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  inline Chordate(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height)
         {
           std::uniform_int_distribution<int> random_w(0, static_cast<int>(grid_width));
           std::uniform_int_distribution<int> random_h(0, static_cast<int>(grid_height));
           head_x = random_w(random_generator::engine);
           head_y = random_h(random_generator::engine);  
        }

  void UpdateHead();

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  bool growing{false};

 private:
  int grid_width;
  int grid_height;

};

#endif