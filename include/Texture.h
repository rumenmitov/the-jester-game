#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

class Texture {
  public:

    static SDL_Texture* LoadTexture(const char* textureSheet);
    static void Render(SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest);
};

#endif
