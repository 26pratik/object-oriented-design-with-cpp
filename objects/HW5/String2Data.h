/*----------------------------------------------------------------
All includes here
YOU CANNOT INCLUDE ANY OTHER FILES
-----------------------------------------------------------------*/
#pragma once
#include "util.h"

/*----------------------------------------------------------------
Declaration of String2Data class
-----------------------------------------------------------------*/
class String2Data
{
public:
  enum DATATYPE
  {
    BOOL = 0,
    LONG,
    DOUBLE,
    STRING
  };
  void static test_conversion();
  // WRITE CODE
  long string_2_long(bool &islong);
  bool string_2_bool(bool &isbool);
  double string_2_double(bool &isdouble);

  String2Data(string &s) : str_(s)
  {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
  };

private:
  // CANNOT ADD ANYTHING
  const string &str_;
};

// EOF
