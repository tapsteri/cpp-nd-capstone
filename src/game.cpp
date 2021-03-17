#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, int frogsNumber)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceFrogs(grid_width, grid_height, frogsNumber);
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();

    RemoveDeadFrogs(); 

    renderer.Render(snake, frogs);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFrogs(int grid_width, int grid_height, int frogsNumber) {
  int x, y;
  for (int i=0; i < frogsNumber; i++) {
      frogs.push_back(std::make_unique<Frog>(grid_width, grid_height));  
  }
}

void Game::Update() {

  if (!snake.alive) return;

  snake.Update();

    for(const auto& frog: frogs) {
    frog->Update();
  }

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's frog over here
  for(const auto& frog: frogs) {
    if (static_cast<int>(frog->head_x) == new_x && static_cast<int>(frog->head_y) == new_y) {
      if (!frog->alive) {
        snake.alive = false;
      } else {
        score++;
        // Grow snake and increase speed.
        snake.GrowBody();
        snake.speed += 0.02;
        frog->alive = false;        
      }
    }
  }
}

void Game::RemoveDeadFrogs() { 

  auto it = frogs.begin();
    while(it != frogs.end()) {
      if(!it->get()->alive)
        it = frogs.erase(it);
      else
        it++;
    }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }