#include "charactersystem.h"

CharacterSystem::CharacterSystem(){
  characters = new Character*[NUMBEROFCHARACTERS];
  for(unsigned i=0; i<NUMBEROFCHARACTERS; i++){
    characters[i] = NULL;
  }
  characters[ciNULL] = new CharNull();
  missing_character = new Sprite("missingcharacter.png");
}

CharacterSystem::~CharacterSystem(){
  for(unsigned i=0; i<NUMBEROFCHARACTERS; i++){
    if (characters[i] != NULL){
      delete characters[i];
      characters[i] = NULL;
    }
  }
  delete[] characters;
  delete missing_character;
}
