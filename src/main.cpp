#include "application.h"

path base_path;
Application* app;

int main(int argc, char* argv[]){
  base_path = path{argv[0]}.parent_path();
  app = new Application();
  if (app->init(argc, argv)){
    while(app->run());
  }
  app->quit();
  return 0;
}
