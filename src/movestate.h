#ifndef MOVESTATE_H
#define MOVESTATE_H

#include "buttontype.h"
#include "buttonstate.h"
#include <vector>
using namespace std;

class MoveState {
  private:
    int ttl;
    int charge;

  public:
    const static int TTL = 20;
    const static int MAXCHARGE = 100;
    MoveState(ButtonType, ButtonState);
    ~MoveState();
    ButtonType button;
    ButtonState state;
    int Ttl(int);
    int Charge(int);
    bool operator==(ButtonType);
    bool operator==(MoveState);
};

#endif
