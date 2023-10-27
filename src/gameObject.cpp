#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include "../include/GameObject.h"
#include "../include/Game.h"
#include "../include/Texture.h"

GameObject::GameObject(const char* textureSheet, int x_init, int y_init) {
  src.w = dest.w = 32;
  src.h = dest.h = 32;

  src.x = 0;
  dest.x = x_init;
  src.y = 0;
  dest.y = y_init;

  texture = Texture::LoadTexture(textureSheet);
}

GameObject::~GameObject() {}

void GameObject::Render() {
  Texture::Render(texture, &src, &dest);
}

SDL_Rect GameObject::GetPosition() {
  return dest;
}
