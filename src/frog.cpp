// This file is intentionally blank
#include <frog.h>

void Frog::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.
  UpdateDirection();
}

void Frog::UpdateDirection() { 
    // The higher the activity the longer the frogs will move straight ahead   
    switch (random_generator::rand_int(0,kFrogActivity)) {
      case 0:
        direction = Direction::kUp;
        break;
      case 1:
        direction = Direction::kDown;
        break;
      case 2:
        direction = Direction::kLeft;
        break;
      case 3:
        direction = Direction::kRight;
        break;
      default:;
    }
}