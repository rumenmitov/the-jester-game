#include <iostream>
#include <SDL2/SDL.h>

#include "../include/Map.h"
#include "../include/Texture.h"

Map::Map() {
  src.w = dest.w = 32;
  src.h = dest.h = 32;

  src.x = dest.x = 0;
  src.y = dest.y = 0;

  water = Texture::LoadTexture("assets/water.png");
  grass = Texture::LoadTexture("assets/grass.png");
  dirt = Texture::LoadTexture("assets/dirt.png");
}

Map::~Map() {}

void Map::Update(int mapArr[40][40]) {
  for (int row = 0; row < 20; row++) {
    for (int col = 0; col < 20; col++) {
      map[row][col] = mapArr[row][col];
    }
  }

}

void Map::Render(SDL_Rect playerRect) {
  for (int row = (playerRect.y / 32) - 5; row < (playerRect.y / 32) + 5; row++) {
    for (int col = (playerRect.x / 32) - 5; col < (playerRect.x / 32) + 5; col++) {
      if (row < 0) {
        row = 0;
      }
      if (col < 0) {
        col = 0;
      }

      dest.x = col * 32;
      dest.y = row * 32;

      switch (map[row][col]) {
        case 0:
          Texture::Render(water, &src, &dest);
          break;
        case 1:
          Texture::Render(grass, &src, &dest);
          break;
        case 2:
          Texture::Render(dirt, &src, &dest);
          break;
        
        default:
          break;
      }
    }
  }
  
}
