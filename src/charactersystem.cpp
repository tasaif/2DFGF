#include "charactersystem.h"

CharacterSystem::CharacterSystem(){
  Character* character;
  for(unsigned i=0; i<8; i++){
    character = new Character();
    character->init("NULL", "mode7.ttf");
    characters.push_back(character);
  }
}

CharacterSystem::~CharacterSystem(){
  while (characters.size()){
    delete characters[0];
    characters.erase(characters.begin());
  }
}
