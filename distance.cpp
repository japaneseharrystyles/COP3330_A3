#include "distance.h"
#include <iostream>

//////////////////////////////////////
//        class constructors        //
//////////////////////////////////////



Distance::Distance () {
  inch = 0;
  foot = 0;
  yard = 0;
  mile = 0;
}

Distance::Distance (int i) {
  if (i >= 0){
    inch = i;
    foot = 0;
    yard = 0;
    mile = 0;
    simplify();
  }
  else{
    inch = 0;
    foot = 0;
    yard = 0;
    mile = 0;
  }
} 

Distance::Distance (int m, int y, int f, int i) {
  if (i >= 0 && f >= 0 && y >= 0 && m >= 0){
    inch = i;
    foot = f;
    yard = y;
    mile = m;
    simplify();
  }
  else{
    inch = 0;
    foot = 0;
    yard = 0;
    mile = 0;
  }
}


//////////////////////////////////////
//        Tristen's functions       //
//////////////////////////////////////

void Distance::simplify() {

  if (inch >= 12){
    foot = foot + (inch / 12);
    inch = inch % 12;
  }
  if (foot >= 3){
    yard = yard + (foot / 3);
    foot = foot % 3;
  }
  if (yard >= 1760){
    mile = mile + (yard / 1760);
    yard = yard % 1760;
  }
}

void Distance::Check() {
  std::cout << mile << " miles\n";
  std::cout << yard << " yards\n";
  std::cout << foot << " feet\n";
  std::cout << inch << " inches\n";
}
