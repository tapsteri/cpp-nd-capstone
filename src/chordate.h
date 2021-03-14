#ifndef CHORDATE_H
#define CHORDATE_H

#include <vector>
#include <random>
#include <ctime>
#include "SDL.h"

class Chordate {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };
  static int objectCount;

  inline Chordate(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height)
         {
        //      head_x = random_w(engine);
           std::mt19937 generator(int(std::time(0)) + objectCount);
           std::uniform_int_distribution<int> random_w(0, static_cast<int>(grid_width));
           std::uniform_int_distribution<int> random_h(0, static_cast<int>(grid_height));
           head_x = random_w(generator);
           head_y = random_h(generator);
           objectCount++;

        }

  void Update();

  void UpdateHead();

  void UpdateDirection();

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;

 private:
  //void UpdateHead();
  bool growing{false};
  int grid_width;
  int grid_height;
  /*
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  */
};

#endif