#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include "../include/Texture.h"
#include "../include/Game.h"

SDL_Texture* Texture::LoadTexture(const char* textureSheet) {
  SDL_Surface* tmpSurface = IMG_Load(textureSheet);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);

  return texture;
}

void Texture::Render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest) {
  SDL_RenderCopy(Game::renderer, texture, src, dest);
}

