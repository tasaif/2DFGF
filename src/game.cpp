#include "game.h"

Game::Game(){
}
                /* init and the constructor were
                 separated because of the
                 releationship between the Game
                 object and Scene objects
                 */

bool Game::init(){
  p = new Player*[2];
  p[0] = new Player();
  p[1] = new Player();

  charsys = new CharacterSystem();

  logo1 = new Billboard(gsLOGO2);
  logo2 = new Billboard(gsINTRO);
  title_menu = new Menu();
  options_menu = new OptionsMenu();
  select_menu = new SelectMenu();
  character_menu = new CharacterMenu(charsys);
  vs_scene = new VSScene(charsys);

  logo1->init("billboard1.bmp");
  logo2->init("billboard2.bmp");
  title_menu->init("mainmenu.png");
  options_menu->init("optionsmenu.png");
  select_menu->init("selectmenu.png");
  character_menu->init("charactermenu.png");
  vs_scene->init();
  fps_display = new TextSprite();
  fps_display->setColor({255, 255, 255});
  fps_display->offset.y = Application::SCREEN_HEIGHT - 15;
  fps_display->init("0");
  was_initialized = true;

  gamestate = gsSELECT;
}

Game::~Game(){
  if (!was_initialized) return;
  delete fps_display;
  delete vs_scene;
  delete logo1;
  delete logo2;
  delete title_menu;
  delete options_menu;
  delete select_menu;
  delete character_menu;
  delete p[0];
  delete p[1];
  delete[] p;
  delete charsys;
}

bool Game::run(){
  switch(gamestate){
    case gsNULL:
      if (debugstate == 1){
        gamestate = gsVS;
        setP1(app->inputsys->getJoysticks().front());
        setP2(app->inputsys->getJoysticks().back());
        vs_scene->first();
      } else {
        gamestate = gsLOGO1;
        logo1->first();
      }
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
          case gsTITLE:
            title_menu->first();
            break;
          case gsCHARACTERS:
            character_menu->first();
          default:
            break;
        };
      }
      break;
    case gsCHARACTERS:
      if (!character_menu->run()){
        gamestate = character_menu->end();
        switch(gamestate){
          case gsVS:
            vs_scene->first();
            break;
          case gsSELECT:
            select_menu->first();
            break;
          default:
            break;
        };
      }
      break;
    case gsVS:
      if (!vs_scene->run()){
        gamestate = vs_scene->end();
        switch(gamestate){
          case gsCHARACTERS:
            character_menu->first();
            break;
          default:
            break;
        };
      }
      break;
    case gsQUIT:
      return false;
  };
  fps_display->init(to_string(app->avgFPS));
  app->drawsys->draw(fps_display);
  return true;
}

void Game::clearP(Joystick* joystick){
  if (joystick == NULL){
    return;
  }
  if (p[0]->joystick == joystick){
    p[0]->joystick = NULL;
  } else if (p[1]->joystick == joystick){
    p[1]->joystick = NULL;
  }
  joystick->getIcon()->align(Sprite::HCENTER);
}

void Game::setP1(Joystick* joystick){
  clearP(p[0]->joystick);
  p[0]->joystick = joystick;
  p[0]->setP(0);
  joystick->getIcon()->offset.x = Application::SCREEN_WIDTH / 4 - joystick->getIcon()->getW()/2;
}

void Game::setP2(Joystick* joystick){
  clearP(p[1]->joystick);
  p[1]->joystick = joystick;
  p[1]->setP(1);
  joystick->getIcon()->offset.x = (Application::SCREEN_WIDTH / 4) * 3 - joystick->getIcon()->getW()/2;
}

Player* Game::getP(unsigned player){
  return p[player];
}

bool Game::isPlayer(unsigned player, Joystick* joystick){
  if (p[player] == NULL) return false;
  return p[player]->joystick == joystick;
}

bool Game::playersReady(){
  return p[0]->joystick != NULL && p[1]->joystick != NULL;
}
