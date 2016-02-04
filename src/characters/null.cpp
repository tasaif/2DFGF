#include "../application.h"
#include "null.h"

extern path character_path;
extern Application* app;

NullChar::NullChar(){
  animsys = app->animsys;
  init("NULL", "mode7.ttf");
  hp = 200;
  for(unsigned i=0; i<psEND; i++){
    base_anim[i] = NULL;
  }
  base_anim[psNEUTRAL] = animsys->makeAnimation(character_path / "null/animations/neutral", 7);
  base_anim[psWALKF] = animsys->makeAnimation(character_path / "null/animations/walkf", 3);
  base_anim[psPRECROUCH] = animsys->makeAnimation(character_path / "null/animations/precrouch", 3);
  base_anim[psCROUCH] = animsys->makeAnimation(character_path / "null/animations/crouch", 10);
  base_anim[psPOSTCROUCH] = animsys->makeAnimation(character_path / "null/animations/postcrouch", 3);
  /*
   * The following values were found qualitatively
   */
  jump_acc = -4;
  walkf_speed = 7;
  walkb_speed = 3;
  jumpf_speed = 10;
  jumpb_speed = 8;
}

NullChar::~NullChar(){
  for(unsigned i=0; i<psEND; i++){
    if (base_anim[i] != NULL){
      delete base_anim[i];
      base_anim[i] = NULL;
    }
  }
}
