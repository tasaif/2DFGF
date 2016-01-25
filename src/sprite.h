#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "boost/filesystem.hpp"
using namespace boost::filesystem;
using namespace std;

class Sprite {
  public:
    Sprite();
    Sprite(string);
    ~Sprite();

    SDL_Surface* surface = NULL;
    SDL_Rect offset;
    void load(string);
    void unload();
    bool valid();
    void setPos(int, int);
    void align(unsigned);
    void alignTo(Sprite*, unsigned);

    static const unsigned HCENTER = 1;
    static const unsigned VBOTTOM = 2;
    static const unsigned VCENTER = 4;
};

#endif
