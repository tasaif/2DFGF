#ifndef APPLICATION_H
#define APPLICATION_H
#include <SDL.h>
#include <SDL_mixer.h>
#include "drawsystem.h"
#include "inputsystem.h"
#include "fontsystem.h"
#include "optionsystem.h"
#include "animationsystem.h"
#include "sparksystem.h"
#include "game.h"
#include "../vendor/lazyfoo/ltimer.h"
using namespace std;

class InputSystem;
class DrawSystem;
class Game;

class Application {
  public:
    const char* TITLE = "2D Fighter";
    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 480;
    static const int SCREEN_FPS = 60;
    static const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
    Uint32 rmask;
    Uint32 gmask;
    Uint32 bmask;
    Uint32 amask;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    DrawSystem* drawsys;
    InputSystem* inputsys;
    FontSystem* fontsys;
    OptionSystem* optionsys;
    AnimationSystem* animsys;
    SparkSystem* sparksys;
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
