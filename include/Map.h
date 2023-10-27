#ifndef MAP_H 
#define MAP_H

#include <SDL2/SDL.h>

class Map {
  private:
    SDL_Rect src, dest;

    SDL_Texture* water;
    SDL_Texture* grass;
    SDL_Texture* dirt;

    int map[40][40];
  public:
    Map();
    ~Map();

    void Update(int mapArr[40][40]);
    void Render(SDL_Rect playerRect);
};

#endif
