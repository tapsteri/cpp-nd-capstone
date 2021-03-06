#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include <memory>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "frog.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, int frogsNumber);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  std::vector<std::unique_ptr<Frog>> frogs;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFrogs(int grid_width, int grid_height, int frogsNumber);
  void Update();
  void RemoveDeadFrogs();
};

#endif