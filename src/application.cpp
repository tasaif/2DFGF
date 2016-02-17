#include <SDL.h>
#include <iostream>
#include "boost/filesystem.hpp"
#include "application.h"
using namespace std;
using namespace boost::filesystem;

bool Application::init(int argc, char* argv[]){
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
    return false;
  }
  if (!(IMG_Init(IMG_INIT_PNG))){
    cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
    return false;
  }
  if (TTF_Init() == -1){
    cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
    return false;
  }
  window = SDL_CreateWindow( TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
  if(window == NULL){
    cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
    return false;
  }
  event = new SDL_Event();
  drawsys = new DrawSystem();
  inputsys = new InputSystem();
  fontsys = new FontSystem();
  optionsys = new OptionSystem();
  animsys = new AnimationSystem();
  sparksys = new SparkSystem(animsys);
  game = new Game();
  game->init();

  fpsTimer.start();
  return true;
}

bool Application::run(){
  bool quit = false;
  capTimer.start();
  if (debugstate == 1){
    //system("sleep .4");
    //system("clear");
  }
  while (SDL_PollEvent(event)){
    switch(event->type){
      case SDL_QUIT:
        quit = true;
        break;
    };
  }
  inputsys->update();
  bool run_again = game->run() and !quit;
  drawsys->update();
  frameLimiter();
  return run_again;
}

void Application::quit(){
  delete sparksys;
  delete fontsys;
  delete optionsys;
  delete animsys;
  delete event;
  delete game;
  delete inputsys;
  delete drawsys;
	SDL_DestroyWindow(window);
	window = NULL;
  IMG_Quit();
  TTF_Quit();
	SDL_Quit();
}

void Application::frameLimiter(){
  avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
  if( avgFPS > 2000000 ){
    avgFPS = 0;
  }
  ++countedFrames;
  int frameTicks = capTimer.getTicks();
  if(frameTicks < SCREEN_TICKS_PER_FRAME){
    SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
  }
}
