#ifndef APPLICATION_H
#define APPLICATION_H
#include <SDL2/SDL.h>
#include "drawsystem.h"
#include "game.h"
#include "ltimer.h"
using namespace std;

class DrawSystem;
class Game;

class Application {
  public:
    const char* TITLE = "2D Fighter";
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int SCREEN_FPS = 60;
    const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
    SDL_Window* gWindow = NULL;
    DrawSystem* drawsys;
    SDL_Event event;
    Game* game;

    LTimer fpsTimer;
    LTimer capTimer;
    int countedFrames = 0;
    float avgFPS;

    bool init(int, char**);
    bool run();
    void quit();

    void frameLimiter();
};
#endif
