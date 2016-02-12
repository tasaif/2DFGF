#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include "buttontype.h"
#include "playerstates.h"
#include "animationsystem.h"
using namespace std;

class Move {
  private:
    vector<ButtonType> command;
    Animation* anim;
    PlayerState type;
    unsigned move_number;
    static ButtonType strToButtonType(string);
    static vector<ButtonType> parseCmd(string);

  public:
    Move();
    ~Move();

    void init(string, Animation*, unsigned, PlayerState);
};

#endif
