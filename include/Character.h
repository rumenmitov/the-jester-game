#ifndef CHARACTER_H
#define CHARACTER_H

#include "GameObject.h"

struct movement {
  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;
};

class Character : public GameObject {
  protected:
    int maxHP;
    int currentHP;
    int speedMod;
    movement isMoving;

  public:
    Character(const char* textureSheet, int x_init, int y_init, int startingHP, int speed);

    void Move(const char* direction);
    void Update();
    void Attack();

    void Render();
};


#endif
