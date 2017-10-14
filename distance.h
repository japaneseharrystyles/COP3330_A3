#include <iostream>

class Distance{

/*****  Overloaded Operators *****/

//      insertion & extraction
  friend std::ostream& operator << (std::ostream&, const Distance&);
  friend std::istream& operator >> (std::istream&, Distance&);

//      comparison operators
  friend bool operator == (const Distance&, const Distance&);
  friend bool operator != (const Distance&, const Distance&);
  friend bool operator < (const Distance&, const Distance&);
  friend bool operator > (const Distance&, const Distance&);
  friend bool operator <= (const Distance&, const Distance&);
  friend bool operator >= (const Distance&, const Distance&);

//      add, subtract, multiply
  friend Distance operator + (const Distance&, const Distance&);
  friend Distance operator - (const Distance&, const Distance&);
  friend Distance operator * (const Distance&, int);


    public:

/*****  Class Constructors  *****/

  Distance();
  Distance(int);
  Distance(int, int, int, int);

/*****  Increment/Decrement  ****/

//       prefix
  Distance& operator ++ ();
  Distance& operator -- ();

//       postfix
  Distance operator ++ (int);
  Distance operator -- (int);

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
