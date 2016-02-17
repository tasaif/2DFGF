#ifndef BUTTONSTATE_H
#define BUTTONSTATE_H

enum ButtonState {
  bsNULL,
  bsPRESSED,
  bsRELEASED,
  bsEND
};

const string legible_button_states[] = {
  "",
  "D",
  "U",
  "?"
};

#endif
