/*----------------------------------------------------------------
Copyright (c) 2023 Author: Pratik Hariya
file: magicsquare.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has magicsquare class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "magicsquare.h"

/*----------------------------------------------------------------
space for static
-----------------------------------------------------------------*/
bool magicsquare::show = false;

// parameterized constructor
magicsquare::magicsquare(int n) : n_(n)
{

    cout << "In constructor " << n_ << endl;

    int r = 0;
    int c = n_ / 2;

    matrix_ = new vector<vector<int> *>(n_);

    for (int i = 0; i < n_; ++i)
    {
        (*matrix_)[i] = new vector<int>(n_, 0);
    }

    int j = 1;
    while (j <= n_ * n_)
    {

        if (r < 0)
        {
            r = n_ - 1;
        }

        if (c == n_)
        {
            c = 0;
        }

        if ((*(*matrix_)[r])[c] != 0)
        {
            r = (r + 2) % n_;
            c = (c - 1 + n_) % n_;
            continue;
        }

        (*(*matrix_)[r])[c] = j;

        j++;
        r--;
        c++;
    }
}

// destructor
magicsquare::~magicsquare()
{
    cout << "In destructor " << n_ << endl;

    for (int i = 0; i < n_; ++i)
    {
        delete (*matrix_)[i];
    }

    delete matrix_;
}

// copy constructor
magicsquare::magicsquare(const magicsquare &ms) : n_(ms.n_)
{
    cout << "In copy constructor " << n_ << endl;

    matrix_ = new vector<vector<int> *>(n_);

    for (int i = 0; i < n_; ++i)
    {
        (*matrix_)[i] = new vector<int>(n_);

        for (int j = 0; j < n_; ++j)
        {
            (*(*matrix_)[i])[j] = (*(*ms.matrix_)[i])[j];
        }
    }
}

// equals operator overloaded
magicsquare &magicsquare::operator=(const magicsquare &ms)
{
    cout << "In equal operator " << n_ << endl;

    if (this == &ms)
    {
        return *this;
    }

    if (n_ != ms.n_)
    {
        throw invalid_argument("Size of both the magicsquares should be same");
    }

    for (int i = 0; i < n_; ++i)
    {
        for (int j = 0; j < n_; ++j)
        {
            (*(*matrix_)[i])[j] = (*(*ms.matrix_)[i])[j];
        }
    }

    return *this;
}

// stream insertion operator overloaded
ostream &operator<<(ostream &os, const magicsquare &ms)
{
    os << "magic square for n";
    os << "= " << ms.n_ << " sum = " << (ms.n_ * ms.n_ + 1) * ms.n_ / 2 << endl;

    if (ms.n_ < 10)
    {
        for (int i = 0; i < ms.n_; ++i)
        {
            for (int j = ms.n_ - 1; j >= 0; --j)
            {
                os << (*(*ms.matrix_)[i])[j] << " ";
            }
            os << endl;
        }
    }

    os << "------------------------------------------------" << endl;

    return os;
}

// return the value at specific row and column
int magicsquare::getRC(int row, int column) const
{
    if (row >= 0 && row < n_ && column >= 0 && column < n_)
    {
        return (*(*matrix_)[row])[column];
    }
    else
    {
        throw out_of_range("Row and/or Column is out of range. Please give row and column values between 0 and " + to_string(n_) + "-1");
    }
}