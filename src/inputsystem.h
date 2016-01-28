#ifndef INPUTSYS_H
#define INPUTSYS_H

#include <vector>
#include "joystick.h"
#include "keyboardjoystick.h"
#include "game.h"
#include "player.h"
using namespace std;

class Game;

class InputSystem {
  private:
    vector<Joystick*> joysticks;
    Game* game = NULL;

  public:
    Player* p1 = NULL;
    Player* p2 = NULL;

    InputSystem();
    ~InputSystem();
    void update();

    bool Pressed(Button);
    bool Pressed(Button, Joystick*&);
    vector<Joystick*> getJoysticks();

    void clearP(Joystick*);
    void setP1(Joystick*);
    void setP2(Joystick*);

};

#endif
