#include "game.h"

Game::Game(){
  logo1 = new Billboard(gsLOGO2);
  logo2 = new Billboard(gsINTRO);
  title_menu = new Menu();
  options_menu = new OptionsMenu();
  select_menu = new SelectMenu();

  logo1->init("billboard1.bmp");
  logo2->init("billboard2.bmp");
  title_menu->init("mainmenu.png");
  options_menu->init("optionsmenu.png");
  select_menu->init("selectmenu.png");
}

Game::~Game(){
  delete logo1;
  delete logo2;
  delete title_menu;
  delete options_menu;
  delete select_menu;
}

bool Game::run(){
  switch(gamestate){
    case gsNULL:
      gamestate = gsLOGO1;
      logo1->first();
      break;
    case gsLOGO1:
      if (!logo1->run()){
        gamestate = logo1->end();
        logo2->first();
      }
      break;
    case gsLOGO2:
      if (!logo2->run()){
        gamestate = logo2->end();
      }
      break;
    case gsINTRO:
      gamestate = gsTITLE;
      title_menu->first();
      break;
    case gsTITLE:
      if(!title_menu->run()){
        gamestate = title_menu->end();
        switch(gamestate){
          case gsOPTIONS:
            options_menu->first();
            break;
          case gsSELECT:
            select_menu->first();
            break;
          default:
            break;
        };
      }
      break;
    case gsOPTIONS:
      if(!options_menu->run()){
        gamestate = options_menu->end();
        switch(gamestate){
          case gsTITLE:
            title_menu->first();
            break;
          default:
            break;
        };
      }
      break;
    case gsSELECT:
      if(!select_menu->run()){
        gamestate = select_menu->end();
        switch(gamestate){
          default:
            break;
        };
      }
      break;
    case gsCHARACTERS:
    case gsVS:
    case gsQUIT:
      return false;
  };
  return true;
}
