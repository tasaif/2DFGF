#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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

    static const int HCENTER = 1;
    static const int VBOTTOM = 2;
};

#endif
