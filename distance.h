#include <iostream>

class Distance{

/*****  Overloaded Operators *****/

  friend std::ostream& operator << (std::ostream& os, const Distance& d);
  friend std::istream& operator >> (std::istream& is, Distance& d);
  friend bool operator == (const Distance& d1, const Distance& d2);
  friend bool operator != (const Distance& d1, const Distance& d2);
  friend bool operator < (const Distance& d1, const Distance& d2);
  friend bool operator > (const Distance& d1, const Distance& d2);
  friend bool operator <= (const Distance& d1, const Distance& d2);
  friend bool operator >= (const Distance& d1, const Distance& d2);

  public:

/*****  Class Constructors  *****/

  Distance();
  Distance(int);
  Distance(int, int, int, int);


  void Check();

  private:

/*****  Private Member Data  *****/

  int inch;
  int foot;
  int yard;
  int mile;

/*****  Tristen's Functions  *****/

  void simplify();
  
}




;
