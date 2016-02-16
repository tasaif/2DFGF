#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL2_rotozoom.h>
#include <iostream>
#include <string>
#include "boost/filesystem.hpp"
using namespace boost::filesystem;
using namespace std;

class Sprite {
  private:
    string fname;
    void init(path, string);
    double angle = 0.0;
    SDL_RendererFlip flip_state = SDL_FLIP_NONE;

  public:
    Sprite();
    Sprite(string);
    Sprite(path, string);
    ~Sprite();

    static void align(Sprite*, SDL_Rect&, unsigned);
    SDL_Texture* texture = NULL;
    SDL_Rect offset;
    void mkRect(unsigned, unsigned, Uint32);
    void load(string);
    void unload();
    bool valid();
    void setPos(int, int);
    void align(unsigned);
    void alignTo(Sprite*, unsigned);
    void alignFromRight(int);
    void rotate(double);
    void setFlipState(SDL_RendererFlip);
    virtual Sprite* duplicate();
    path custom_path = "";
    void dump();
    int getW();
    int getH();
    double getAngle();
    SDL_RendererFlip getFlipState();

    static const unsigned HCENTER = 1;
    static const unsigned VBOTTOM = 2;
    static const unsigned VCENTER = 4;
};

#endif
