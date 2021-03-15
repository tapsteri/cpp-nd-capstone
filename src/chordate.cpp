#include <cmath>
#include <ctime>
#include <iostream>
#include "chordate.h"

void Chordate::Update() {
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

void Chordate::UpdateDirection() {   
    switch (random_generator::rand_int(0,30)) {
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
      default:
        break;
    }
}

void Chordate::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Chordate around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}