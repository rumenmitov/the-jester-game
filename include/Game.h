#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

class Game {
  private:
    SDL_Window* window;

  public: 
    static int windowWidth, windowHeight;

    static SDL_Renderer* renderer;

    bool exitGame = false;

    Game(const char* title, int width, int height, bool fullScreen);
    ~Game();

    void HandleEvents();
    void Update();
    void Render();

}; 

#endif
