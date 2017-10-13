
class Distance{

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
};
