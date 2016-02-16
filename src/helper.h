#ifndef HELPER_H
#define HELPER_H

#include "SDL.h"

void swapInts(int&, int&);
bool inBetween(int, int, int);

struct Point : public SDL_Point {
  Point(int, int);
  ~Point();
};

#endif
