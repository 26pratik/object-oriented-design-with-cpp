/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ninetynine.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ninetynine_H
#define ninetynine_H

#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of ninetynine class
-----------------------------------------------------------------*/
class ninetynine
{
private:
  const int MAX = 99;
  // WRITE ALL PRIVATE FUNCTIONS HERE
  void stanzaPointer_(int n);
  bool compute_string_(int n, const char **m, const char **s);

  void stanzaReference_(int n);
  bool compute_string_(int n, const char *&m, const char *&s);

  void print_(const char *a, const char *b, bool b1, const char *c, const char *d, bool b2);

  // WRITE ALL STRING INITIALIZATIONS HERE
  const char *onesArray[11] = {"nine", "eight", "seven", "six", "five", "four", "three", "two", "one", "zero", ""};
  const char *tensArray[9] = {"ninety", "eighty", "seventy", "sixty", "fifty", "forty", "thirty", "twenty"};
  const char *teensArray[10] = {"nineteen", "eighteen", "seventeen", "sixteen", "fifteen", "fourteen", "thirteen", "twelve", "eleven", "ten"};

public:
  // NOTHING CAN BE ADDED IN PUBLIC
  void run();
};

#endif
