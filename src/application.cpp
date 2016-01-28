#include <SDL.h>
#include <iostream>
#include "boost/filesystem.hpp"
#include "application.h"
using namespace std;
using namespace boost::filesystem;

bool Application::init(int argc, char* argv[]){
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
  gWindow = SDL_CreateWindow( TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
  if( gWindow == NULL ){
    cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
    return false;
  }
  event = new SDL_Event();
  drawsys = new DrawSystem();
  inputsys = new InputSystem();
  fontsys = new FontSystem();
  optionsys = new OptionSystem();
  game = new Game();

  inputsys->p1 = game->p[0];
  inputsys->p2 = game->p[1];

  fpsTimer.start();
  return true;
}

bool Application::run(){
  bool quit = false;
  capTimer.start();
  while (SDL_PollEvent(event)){
    switch(event->type){
      case SDL_QUIT:
        quit = true;
        break;
    };
  }
  inputsys->update();
  bool run_again = game->run() and !quit;
  SDL_UpdateWindowSurface( gWindow );
  frameLimiter();
  return run_again;
}

void Application::quit(){
  delete event;
  delete game;
  delete inputsys;
  delete drawsys;
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
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
