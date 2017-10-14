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

bool operator == (const Distance& d1, const Distance& d2){
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

bool operator != (const Distance& d1, const Distance& d2){
  return !(d1==d2);
}

bool operator < (const Distance& d1, const Distance& d2){
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

bool operator > (const Distance& d1, const Distance& d2){
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

bool operator <= (const Distance& d1, const Distance& d2){
  return !(d1 > d2);
}

bool operator >= (const Distance& d1, const Distance& d2){
  return !(d1 < d2);
}


//////////////////////////////////////
//      Add, Subtract, Multiply     //
//////////////////////////////////////

Distance operator + (const Distance& d1, const Distance& d2) {
  Distance sum;
  sum.inch = d1.inch + d2.inch;
  sum.foot = d1.foot + d2.foot;
  sum.yard = d1.yard + d2.yard;
  sum.mile = d1.mile + d2.mile;
  sum.simplify();
  return sum;
}

Distance operator - (const Distance& d1, const Distance& d2) {
  Distance diff;
  if (d1 > d2){
    diff.inch = d1.inch - d2.inch;
    diff.foot = d1.foot - d2.foot;
    diff.yard = d1.yard - d2.yard;
    diff.mile = d1.mile - d2.mile;
    diff.simplify();
  }
  else{
    diff = 0;
  } 
    return diff;
}

Distance operator * (const Distance& d, int n) {
  Distance prod;
  prod.inch = d.inch * n;
  prod.foot = d.foot * n;
  prod.yard = d.yard * n;
  prod.mile = d.mile * n;
  prod.simplify();
  return prod;
}


//////////////////////////////////////
//       Increment & Decrement      //
//////////////////////////////////////

Distance& Distance::operator ++ () {
  inch++;
  simplify();
  return *this;
}

Distance& Distance::operator -- () {
  inch--;
  simplify();
  return *this;
}

Distance Distance::operator ++ (int) {
  Distance temp = *this;
  inch++;
  simplify();
  return temp;
}

Distance Distance::operator -- (int) {
  Distance temp = *this;
  inch--;
  simplify();
  return temp;
}


//////////////////////////////////////
//        Tristen's functions       //
//////////////////////////////////////

void Distance::simplify() {

  while (inch < 0){
    inch = inch + 12;
    foot = foot - 1;
  }
  if (inch >= 12){
    foot = foot + (inch / 12);
    inch = inch % 12;
  }
  while (foot < 0){
    foot = foot + 3;
    yard = yard - 1;
  }
  if (foot >= 3){
    yard = yard + (foot / 3);
    foot = foot % 3;
  }
  while (yard < 0){
    yard = yard + 1760;
    mile = mile - 1;
  }
  if (yard >= 1760){
    mile = mile + (yard / 1760);
    yard = yard % 1760;
  }
}

