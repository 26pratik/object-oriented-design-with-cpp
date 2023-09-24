/*----------------------------------------------------------------
Copyright (c) 2019 Author: Jagadeesh Vasudevamurthy
file: ninetynine.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"

/*----------------------------------------------------------------
Ninety nine bottles of beer on the wall,
Ninety nine bottles of beer,
Take one down, pass it around,
Ninety eight bottles of beer on the wall.

One bottle of beer on the wall,
One bottle of beer,
Take one down, pass it around,
Zero bottle of beer on the wall.
(91)
a = Ninety
b = one
bool true
(90)
c = Ninety
d = ""
bool true

YOU GET a,b, bool
YOU GER c,d, bool

PRINT ONE STANZA HERE
----------------------------------------------------------------*/

static const char *bottle[] = {"bottle", "bottles"};

void ninetynine::print_(const char *a, const char *b, bool b1, const char *c, const char *d, bool b2)
{
  const char *bot = bottle[b1];
  cout << a << " " << b << " " << bot << " of beer on the wall," << endl;
  cout << a << " " << b << " " << bot << " of beer," << endl;
  cout << "Take one down, pass it around," << endl;
  bot = bottle[b2];
  cout << c << " " << d << " " << bot << " of beer on the wall," << endl;
  cout << endl;
}

/*----------------------------------------------------------------
NOTHING CAN BE CHANGED BELOW
*----------------------------------------------------------------*/
void ninetynine::run()
{
  cout << "REFERENCE BASED SONG\n";
  for (int i = MAX; i > 0; --i)
  {
    stanzaReference_(i);
  }
  cout << "POINTER BASED SONG\n";
  for (int i = MAX; i > 0; --i)
  {
    stanzaPointer_(i);
  }
}

// EOF
