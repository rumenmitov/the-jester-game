#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include "../include/Character.h"
#include "../include/Game.h"
#include "../include/GameObject.h"
#include "../include/Texture.h"

Character::Character(const char* textureSheet, int x_init, int y_init, int startingHP, int speed) : GameObject(textureSheet, x_init, y_init) {
  maxHP = currentHP = startingHP;
  speedMod = speed;
};

void Character::Move(const char* direction) {
    if (strcmp(direction, "up") == 0) {
      isMoving.up = true;
    } else if (strcmp(direction, "down") == 0) {
      isMoving.down = true;
    } else if (strcmp(direction, "left") == 0) {
      isMoving.left = true;
    } else if (strcmp(direction, "right") == 0) {
      isMoving.right = true;
    }
}

void Character::Update() {
  int row = dest.y / 32;
  int col = dest.x / 32;

  if (isMoving.up && dest.y - (32 * speedMod) >= 0) {
    dest.y -= 32 * speedMod;
  }
  isMoving.up = false;

  if (isMoving.down && dest.y + (32 * speedMod) < Game::windowHeight) {
    dest.y += 32 * speedMod;
  }
  isMoving.down = false;

  if (isMoving.left && dest.x - (32 * speedMod) >= 0) {
    dest.x -= 32 * speedMod;
  }
  isMoving.left = false;

  if (isMoving.right && dest.x + (32 * speedMod) < Game::windowWidth) {
    dest.x += 32 * speedMod;
  }
  isMoving.right = false;
}

void Character::Attack() {}

void Character::Render() {
  Texture::Render(texture, &src, &dest);

  SDL_Rect healthbar;
  healthbar.w = (currentHP / maxHP) * dest.w;
  healthbar.h = 3;
  healthbar.x = dest.x;
  healthbar.y = dest.y - healthbar.h - 2;

  SDL_SetRenderDrawColor(Game::renderer, 0, 0, 255, 255);
  SDL_RenderFillRect(Game::renderer, &healthbar);
}
