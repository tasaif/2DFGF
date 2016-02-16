#include "helper.h"

void swapInts(int& lhs, int& rhs){
  int tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

bool inBetween(int left, int middle, int right){
  if (left > right){
    swapInts(left, right);
  }
  return middle >= left && middle <= right;
}

Point::Point(int _x, int _y){
  x = _x;
  y = _y;
}

Point::~Point(){
}
