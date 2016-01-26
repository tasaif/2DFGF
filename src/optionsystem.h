#ifndef OPTIONSYSTEM_H
#define OPTIONSYSTEM_H

#include <SDL_mixer.h>

class OptionSystem {
  private:
    unsigned bgmvolume = 50;
    unsigned sfxvolume = 50;
    int match_duration = 99;
    int incValue(int curval, int step, int min, int max){
      int tens_digit = curval % 10;
      curval += step;

      if (tens_digit < 5){
        curval -= tens_digit;
      } else {
        curval += 10 - tens_digit;
      }
      if (curval > max) curval = max;
      if (curval < min) curval = min;
      return curval;
    }

  public:
    OptionSystem();
    ~OptionSystem();

    unsigned getBGMVolume(){
      return bgmvolume;
    }

    unsigned getSFXVolume(){
      return sfxvolume;
    }

    unsigned getMatchDuration(){
      return match_duration;
    }

    void incBGMVolume(int step){
      bgmvolume = incValue(bgmvolume, step, 0, 100);
    }

    void incSFXVolume(int step){
      sfxvolume = incValue(sfxvolume, step, 0, 100);
    }

    void incMatchDuration(int step){
      match_duration = incValue(match_duration, step, 0, 99); //Negative numbers mean infinite
    }
};

#endif
