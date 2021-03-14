#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "chordate.h"

class Snake : public Chordate {
 public:
  Snake (int grid_width, int grid_height) : Chordate (grid_width, grid_height ) {}

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);

  std::vector<SDL_Point> body;

 private:
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif