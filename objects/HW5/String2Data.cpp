/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: String2Data.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
You cannot include any library here
-----------------------------------------------------------------*/
#include "String2Data.h"

/*----------------------------------------------------------------
WRITE CODE
-----------------------------------------------------------------*/

bool String2Data::string_2_bool(bool &isbool)
{
    isbool = false;
    int result = 0;

    if (str_ == "true" || str_ == "false")
    {
        isbool = true;
        return true;
    }

    return false;
}

long String2Data::string_2_long(bool &islong)
{

    islong = false;
    long result = 0;

    istringstream stream(str_);
    char c;
    if (stream >> result && !(stream >> c))
    {
        islong = true;
    }

    return result;
}

double String2Data::string_2_double(bool &isdouble)
{

    isdouble = false;
    double result = 0.0;

    istringstream stream(str_);
    char c;
    if (stream >> result && !(stream >> c))
    {
        isdouble = true;
    }

    return result;
}
