#include "../application.h"
#include "null.h"
#include "../moves/null.h"

extern path character_path;
extern Application* app;

NullChar::NullChar(){
  animsys = app->animsys;
  movesys = new NullMoveSystem();
  init("NULL", "mode7.ttf");
  hp = 200;
  norm_anim = new Animation*[nunEND];
  for(unsigned i=0; i<psEND; i++){
    base_anim[i] = NULL;
  }
  for(unsigned i=0; i<nunEND; i++){
    norm_anim[i] = NULL;
  }
  base_anim[psNEUTRAL] = animsys->makeAnimation(character_path / "null/animations/neutral", 5);
  base_anim[psWALKB] = animsys->makeAnimation(character_path / "null/animations/walkb", 4);
  base_anim[psWALKF] = animsys->makeAnimation(character_path / "null/animations/walkf", 4);
  base_anim[psPRECROUCH] = animsys->makeAnimation(character_path / "null/animations/precrouch", 1);
  base_anim[psCROUCH] = animsys->makeAnimation(character_path / "null/animations/crouch", 5);
  base_anim[psPOSTCROUCH] = animsys->makeAnimation(character_path / "null/animations/postcrouch", 1);
  norm_anim[nunLP] = animsys->makeAnimation(character_path / "null/animations/standinglp", 2);

  base_anim[psNEUTRAL]->mkDefBox(0, 6, animsys->mkBox(10, 180, 35, 50));
  base_anim[psNEUTRAL]->mkDefBox(0, 6, animsys->mkBox(0, 140, 100, 60));
  base_anim[psNEUTRAL]->mkDefBox(0, 6, animsys->mkBox(-10, 80, 75, 80));
  base_anim[psNEUTRAL]->mkDefBox(0, 6, animsys->mkBox(0, 0, 100, 80));
  base_anim[psNEUTRAL]->mkAtkBox(0, 6, animsys->mkBox(85, 170, 45, 20));

  norm_anim[nunLP]->mkAtkBox(1, 2, animsys->mkBox(85, 170, 45, 20));

  /*
   * The following values were found qualitatively
   */
  jump_acc = -4;
  walkf_speed = 6;
  walkb_speed = 3;
  jumpf_speed = 10;
  jumpb_speed = 8;
}

NullChar::~NullChar(){
  delete movesys;
  for(unsigned i=0; i<psEND; i++){
    if (base_anim[i] != NULL){
      delete base_anim[i];
      base_anim[i] = NULL;
    }
  }
}
