/*----------------------------------------------------------------
Copyright (c) 2023 Author: Pratik Hariya
file: intmatrix2.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2  class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except ../util/util.h
-----------------------------------------------------------------*/
#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of intmatrix2 class
-----------------------------------------------------------------*/
class intmatrix2
{
public:
  // WRITE CODE.
  // CANNOT DECLARE ANY GLOBAL VARIABLE

  // USE this as is. I will explain when I show
  static void makeShowOn() { _show = true; }
  static void makeShowOff() { _show = false; }
  static bool show() { return _show; }

  intmatrix2(const intmatrix2 &a);
  intmatrix2(const string &s);
  intmatrix2(int r = 0, int c = 0, int x = 0);

  friend ostream &operator<<(ostream &s, const intmatrix2 &a);

  intmatrix2 &operator=(const intmatrix2 &rhs);

  friend bool operator!(const intmatrix2 &mat)
  {
    return (mat.rows__ == 0 || mat.cols__ == 0);
  }

  // Add Matrix
  intmatrix2 add(const intmatrix2 &other) const;

  // Multiply Matrix
  intmatrix2 mult(const intmatrix2 &other) const;

  bool isEqual(const intmatrix2 &a) const;

  ~intmatrix2();

private:
  static bool _show; // MUST USE THIS
  // WRITE CODE BELOW
  // use xxx_ so that we know all variables are private
  int rows__;
  int cols__;
  int datapoint__;
  int **data__;
  void copy__(const intmatrix2 &matrix);
  void release__();
  void print__();
};

// EOF
