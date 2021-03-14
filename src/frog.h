#ifndef FROG_H
#define FROG_H

#include <vector>
#include "chordate.h"
#include "SDL.h"

class Frog : public Chordate {
 public:
  Frog (int grid_width, int grid_height) : Chordate (grid_width, grid_height ) {}

 private:
  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif