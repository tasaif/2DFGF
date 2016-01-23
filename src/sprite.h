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
    int x = 0;
    int y = 0;
    void load(string);
    void unload();
    bool valid();
};

#endif
