#include "application.h"

path base_path;
path asset_path;
path character_path;
path image_path;
path font_path;
Application* app;
unsigned debugstate = 1;

void printSDLVersion(){
  SDL_version compiled;
  SDL_version linked;
  SDL_VERSION(&compiled);
  SDL_GetVersion(&linked);
  printf("Compiled SDL version %d.%d.%d ...\n",
             compiled.major, compiled.minor, compiled.patch);
  printf("Linked SDL version %d.%d.%d.\n",
             linked.major, linked.minor, linked.patch);
}

int main(int argc, char* argv[]){
  printSDLVersion();
  base_path = path{argv[0]}.parent_path();
  asset_path = base_path / "asset";
  character_path = asset_path / "character";
  image_path = asset_path / "image";
  font_path = asset_path / "font";
  app = new Application();
  if (app->init(argc, argv)){
    while(app->run());
  }
  app->quit();
  return 0;
}
