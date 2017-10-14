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
//      Insertion & Extraction      //
//////////////////////////////////////

std::ostream& operator << (std::ostream& os, const Distance& d) { 
  os << '(';
  if (d.mile > 0){
    os << d.mile;
    os << 'm' << " ";
  }
  if (d.yard > 0){
    os << d.yard;
    os << 'y' << " ";
  }
  if (d.foot > 0){
    os << d.foot;
    os << '\'' << " ";
  }
  os << d.inch;
  os << '\"';
  os << ')';
  return os;
}
std::istream& operator >> (std::istream& is, Distance& d) { 
  int m, y, f, i;
  char comma;
  is >> m;
  is >> comma;
  is >> y;
  is >> comma;
  is >> f;
  is >> comma;
  is >> i;
  if (i >= 0 && f >= 0 && y >= 0 && m >= 0){
    d.inch = i;
    d.foot = f;
    d.yard = y;
    d.mile = m;
    d.simplify();
  }
  else{
    d.inch = 0;
    d.foot = 0;
    d.yard = 0;
    d.mile = 0;
  }
  return is;
}
    
//////////////////////////////////////
//      Comparison Operators        //
//////////////////////////////////////

bool operator == (const Distance &d1, const Distance& d2){
  if (d1.mile != d2.mile)
    return false;
  if (d1.yard != d2.yard)
    return false;
  if (d1.foot != d2.foot)
    return false;
  if (d1.inch != d2.inch)
    return false;
  return true;
}

bool operator != (const Distance &d1, const Distance& d2){
  return !(d1==d2);
}

bool operator < (const Distance &d1, const Distance& d2){
  if (d1.mile < d2.mile)
    return true;
  if (d1.mile > d2.mile)
    return false;
  if (d1.yard < d2.yard)
    return true;
  if (d1.yard > d2.yard)
    return false;
  if (d1.foot < d2.foot)
    return true;
  if (d1.foot > d2.foot)
    return false;
  if (d1.inch < d2.inch)
    return true;
  return false;
}

bool operator > (const Distance &d1, const Distance& d2){
  if (d1.mile > d2.mile)
    return true;
  if (d1.mile < d2.mile)
    return false;
  if (d1.yard > d2.yard)
    return true;
  if (d1.yard < d2.yard)
    return false;
  if (d1.foot > d2.foot)
    return true;
  if (d1.foot < d2.foot)
    return false;
  if (d1.inch > d2.inch)
    return true;
  return false;
}

bool operator <= (const Distance &d1, const Distance& d2){
  return !(d1 > d2);
}

bool operator >= (const Distance &d1, const Distance& d2){
  return !(d1 < d2);
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
