#include "option.h"

Option::Option(unsigned _applicable_state):applicable_state(_applicable_state){
  press_func = new std::function<void()>[bEND];
  for(unsigned i=0; i<bEND; i++){
    press_func[i] = NULL;
  }
}

Option::~Option(){
  delete[] press_func;
}

unsigned Option::getApplicableState(){
  return applicable_state;
}
