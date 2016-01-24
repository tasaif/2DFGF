#include <SDL2/SDL.h>
#include <iostream>
#include "boost/filesystem.hpp"
#include "application.h"
using namespace std;
using namespace boost::filesystem;

bool Application::init(int argc, char* argv[]){
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
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
  game = new Game();
  fpsTimer.start();
  return true;
}

bool Application::run(){
  capTimer.start();
  SDL_PollEvent(event);
  bool run_again = game->run() and event->type != SDL_QUIT;
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
