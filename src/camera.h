#ifndef CAMERA_H
#define CAMERA_H

#include "drawsystem.h"
#include "sprite.h"
#include "sparksystem.h"

class DrawSystem;
class Stage;
class Player;
class Spark;

class Camera {
  private:
    DrawSystem* drawsys;
    SDL_Rect offset;
    Stage* stage;
    int parallax_factor;

  public:
    Camera(DrawSystem*);
    ~Camera();

    void setStage(Stage*);
    void setFocus(SDL_Rect);
    void draw(Sprite*);
    bool draw(Spark*);
    void draw(Sprite*, SDL_Rect);
    void draw(Sprite*, SDL_Rect, Player*);
    void drawBG();
    void drawBox(HitBox, Uint32);
    void drawBox(vector<HitBox>, Uint32);
};

#endif
