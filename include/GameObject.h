#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

class GameObject {
  protected:
    SDL_Rect src, dest;
    SDL_Texture* texture;

  public:
    GameObject(const char* textureSheet, int x_init, int y_init);
    ~GameObject();

   void Render();
   SDL_Rect GetPosition();
};

#endif
