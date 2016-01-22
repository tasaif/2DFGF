#ifndef APPLICATION_H
#define APPLICATION_H
#include <SDL2/SDL.h>
#include "drawsystem.h"
#include "game.h"
using namespace std;

class DrawSystem;
class Game;

class Application {
  public:
    const char* TITLE = "2D Fighter";
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    SDL_Window* gWindow = NULL;
    DrawSystem* drawsys;
    Game* game;

    bool init(int, char**);
    bool run();
    void quit();
};
#endif
