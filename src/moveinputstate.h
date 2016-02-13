#ifndef BUTTON_H
#define BUTTON_H

#include "buttontype.h"
#include "buttonstate.h"
#include <vector>
using namespace std;

class Button {
  public:
    const static int TTL = 20;
    Button();
    ~Button();
    vector<ButtonType> types; //Multiple buttons at once
    int ttl;
    int charge;
    void push(ButtonType);
};

#endif
