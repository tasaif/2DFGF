#ifndef BUTTONTYPE_H
#define BUTTONTYPE_H

#include <string>
using namespace std;

enum ButtonType {
  bNULL,
  bUP,
  bDOWN,
  bLEFT,
  bRIGHT,
  bUPLEFT,
  bUPRIGHT,
  bDOWNLEFT,
  bDOWNRIGHT,
  bSTART,
  bSELECT,
  bLP,
  bMP,
  bHP,
  bLK,
  bMK,
  bHK,
  bEND
};

const string legible_buttons[] = {
  "  ",
  "↑ ",
  "↓ ",
  "← ",
  "→ ",
  "↖ ",
  "↗ ",
  "↙ ",
  "↘ ",
  "S ",
  "s ",
  "□ ",
  "△ ",
  "R1",
  "X ",
  "O ",
  "R2",
  "EN"
};

#endif
