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
  drawsys = new DrawSystem();
  game = new Game();
  return true;
}

bool Application::run(){
  SDL_PollEvent(&event);
  bool run_again = game->run() and event.type != SDL_QUIT;
  SDL_UpdateWindowSurface( gWindow );
  SDL_Delay( 1 );
  return run_again;
}

void Application::quit(){
  delete game;
  delete drawsys;
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	SDL_Quit();
}
