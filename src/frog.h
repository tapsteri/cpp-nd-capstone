#ifndef FROG_H
#define FROG_H

#include <vector>
#include "SDL.h"

class Frog {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Frog(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();

  bool FrogCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif