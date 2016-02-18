#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include "buttontype.h"
#include "playerstates.h"
#include "animationsystem.h"
#include "movestate.h"
using namespace std;

class Move {
  private:
    string name;
    vector<MoveState> command;
    Animation* anim;
    PlayerState type;
    unsigned move_number;
    static ButtonType keyToButtonType(string);
    static vector<MoveState> parseCmd(string);

  public:
    Move();
    ~Move();

    void init(string, Animation*, unsigned, PlayerState, string);
    void dump();
    void dump(bool);
    vector<MoveState>* getCmd();
    string getName();
    PlayerState getType();
    int getIndex();
};

#endif
