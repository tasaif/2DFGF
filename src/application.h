#ifndef APPLICATION_H
#define APPLICATION_H
#include <SDL.h>
#include <SDL_mixer.h>
#include "drawsystem.h"
#include "inputsystem.h"
#include "fontsystem.h"
#include "optionsystem.h"
#include "game.h"
#include "ltimer.h"
using namespace std;

class DrawSystem;
class Game;

class Application {
  public:
    const char* TITLE = "2D Fighter";
    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 480;
    static const int SCREEN_FPS = 60;
    static const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
    SDL_Window* gWindow = NULL;
    DrawSystem* drawsys;
    InputSystem* inputsys;
    FontSystem* fontsys;
    OptionSystem* optionsys;
    SDL_Event* event;
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
