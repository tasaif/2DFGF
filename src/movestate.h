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
    bool confirmed;

  public:
    const static int TTL = 20;
    const static int MAXCHARGE = 100;
    MoveState(ButtonType, ButtonState);
    MoveState(ButtonType, ButtonState, int);
    ~MoveState();
    ButtonType button;
    ButtonState state;
    int Ttl(int);
    int Charge(int);
    void Confirm();
    bool Confirmed();
    bool operator==(MoveState);
    MoveState duplicate();
};

#endif
