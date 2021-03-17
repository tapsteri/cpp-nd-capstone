#ifndef FROG_H
#define FROG_H

#include <vector>
#include "chordate.h"
#include "SDL.h"

constexpr int kFrogActivity{100};

class Frog : public Chordate {
 public:
  Frog (int grid_width, int grid_height) : Chordate (grid_width, grid_height ) {}

  void Update();

 private:
  void UpdateDirection();

};

#endif