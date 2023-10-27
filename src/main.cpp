#include <SDL2/SDL_timer.h>
#include <iostream>
#include <SDL2/SDL.h>

#include "../include/Game.h"

const int FPS = 60;
const int frameDelay = 1000 / FPS;


int main(int argc, char* args[]) {

  Game* game = new Game("The Jester Game", 640, 640, false);

  while(!game->exitGame) {
    game->HandleEvents();
    game->Update();
    game->Render();

    SDL_Delay(frameDelay);

  }

  delete game;
  game = nullptr;

  SDL_Quit();

  return 0;
}
