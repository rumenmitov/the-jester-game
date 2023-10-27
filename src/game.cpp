#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../include/Game.h"
#include "../include/Texture.h"
#include "../include/Map.h"
#include "../include/GameObject.h"
#include "../include/Character.h"

#include "levels/1.cpp"

int Game::windowWidth;
int Game::windowHeight;

SDL_Renderer* Game::renderer = nullptr;

Map* map;
Character* player; 

Game::Game(const char* title, int width, int height, bool fullScreen) {
  windowWidth = width;
  windowHeight = height;

  int flags = 0;
  if (fullScreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  map = new Map();

  player = new Character("assets/player.png", 0, 0, 10, 1);
}

Game::~Game() {
  SDL_DestroyWindow(window);
  window = nullptr;

  SDL_DestroyRenderer(renderer);
  renderer = nullptr;

  delete player;
  player = nullptr;
}

void Game::HandleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);

  if (event.type == SDL_QUIT) {
    exitGame = true;
  } else if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
      case SDLK_w:
        player->Move("up");
        break;
      case SDLK_s:
        player->Move("down");
        break;
      case SDLK_a:
        player->Move("left");
        break;
      case SDLK_d:
        player->Move("right");
        break;

      default:
        break;
    }
  }
}

void Game::Update() {
  map->Update(lvl1);
  player->Update();
}

void Game::Render() {
  SDL_RenderClear(renderer);
  map->Render(player->GetPosition());
  player->Render();
  SDL_RenderPresent(renderer);
}
