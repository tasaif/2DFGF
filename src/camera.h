#ifndef CAMERA_H
#define CAMERA_H

#include "drawsystem.h"
#include "sprite.h"

class Camera {
  private:
    DrawSystem* drawsys;
    SDL_Rect offset;

  public:
    Camera(DrawSystem*);
    ~Camera();

    void setFocus(SDL_Rect);
    void draw(Sprite*);
    void draw(Sprite*, SDL_Rect);
};

#endif
