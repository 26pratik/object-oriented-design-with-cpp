/*----------------------------------------------------------------
Copyright (c) 2019 Author: Pratik Hariya
file: ninetyninereferencebased
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
compute strings. reference based
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"

/*----------------------------------------------------------------
compute strings object based
YOU GET
n
and you have to generate a and b

if n = 90
a = string Ninety
b = empty string
bool is true

if n = 1
a = string one
b = empty string
bool is false
----------------------------------------------------------------*/
bool ninetynine::compute_string_(int n, const char *&m, const char *&s)
{
  bool plural = true;
  // WRITE CODE
  int ones, tens;
  ones = n % 10;
  tens = n / 10;

  if (n >= 20)
  {
    switch (tens)
    {
    case 9:
      m = tensArray[0];
      break;
    case 8:
      m = tensArray[1];
      break;
    case 7:
      m = tensArray[2];
      break;
    case 6:
      m = tensArray[3];
      break;
    case 5:
      m = tensArray[4];
      break;
    case 4:
      m = tensArray[5];
      break;
    case 3:
      m = tensArray[6];
      break;
    case 2:
      m = tensArray[7];
      break;
    }
    switch (ones)
    {
    case 9:
      s = onesArray[0];
      break;
    case 8:
      s = onesArray[1];
      break;
    case 7:
      s = onesArray[2];
      break;
    case 6:
      s = onesArray[3];
      break;
    case 5:
      s = onesArray[4];
      break;
    case 4:
      s = onesArray[5];
      break;
    case 3:
      s = onesArray[6];
      break;
    case 2:
      s = onesArray[7];
      break;
    case 1:
      s = onesArray[8];
      break;
    case 0:
      s = onesArray[10];
      break;
    }
  }
  else if (n <= 19 & n >= 10)
  {
    s = "";
    switch (n)
    {
    case 19:
      m = teensArray[0];
      break;
    case 18:
      m = teensArray[1];
      break;
    case 17:
      m = teensArray[2];
      break;
    case 16:
      m = teensArray[3];
      break;
    case 15:
      m = teensArray[4];
      break;
    case 14:
      m = teensArray[5];
      break;
    case 13:
      m = teensArray[6];
      break;
    case 12:
      m = teensArray[7];
      break;
    case 11:
      m = teensArray[8];
      break;
    case 10:
      m = teensArray[9];
      break;
    }
  }
  else
  {
    s = "";
    switch (ones)
    {
    case 9:
      m = onesArray[0];
      break;
    case 8:
      m = onesArray[1];
      break;
    case 7:
      m = onesArray[2];
      break;
    case 6:
      m = onesArray[3];
      break;
    case 5:
      m = onesArray[4];
      break;
    case 4:
      m = onesArray[5];
      break;
    case 3:
      m = onesArray[6];
      break;
    case 2:
      m = onesArray[7];
      break;
    case 1:
      m = onesArray[8];
      break;
    case 0:
      m = onesArray[9];
      break;
    }
  }
  if (n == 1)
  {
    plural = false;
  }
  else
  {
    plural = true;
  }

  return plural;
}

/*----------------------------------------------------------------
compute strings using Objects
*----------------------------------------------------------------*/
void ninetynine::stanzaReference_(int n)
{

  // WRITE CODE
  const char *a = new char;
  const char *b = new char;
  const char *c = new char;
  const char *d = new char;

  // MUST CALL compute_string_
  bool b1 = compute_string_(n, a, b);
  bool b2 = compute_string_(n - 1, c, d);

  // MUST CALL PRINT which prints a stanza
  print_(a, b, b1, c, d, b2);
}

// EOF
