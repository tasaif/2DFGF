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
    MoveState();
    ~MoveState();
    ButtonType button;
};

#endif
