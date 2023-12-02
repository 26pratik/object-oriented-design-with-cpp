/*----------------------------------------------------------------
Copyright (c) 2023 Author: Pratik Hariya
file: composition.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
RUN TWICE. OUTPUT MUST BE SAME
-----------------------------------------------------------------*/
#define RAWPOINTER
// #define UNIQUEPOINTER

#pragma once
/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include <iomanip> // std::setprecisio
using namespace std;

#ifdef _WIN32
#include <cassert>
#include <ctime>
#else
#include <assert.h>
#include <time.h>
#endif

/*----------------------------------------------------------------
Basic defines here
-----------------------------------------------------------------*/
static const int SHOW = 1;

/*----------------------------------------------------------------
mstring class
-----------------------------------------------------------------*/
class mstring
{
public:
  mstring(const char *s) : s_(nullptr)
  {
    if (SHOW)
    {
      cout << "in mstring constructor ";
      if (s)
      {
        cout << s;
      }
      cout << endl;
    }
    allocate_(s);
  }

  ~mstring()
  {
    if (SHOW)
    {
      cout << "in mstring distructor ";
      if (*(this))
      {
        cout << *(this);
      }
      cout << endl;
    }
    _free();
  }

  mstring(const mstring &rhs)
  {
    if (SHOW)
    {
      cout << "in mstring copy constructor ";
      if (rhs)
      {
        cout << rhs;
      }
      cout << endl;
    }
    if (rhs)
    {
      allocate_(rhs.gets_()->c_str());
    }
  }

  mstring &operator=(const mstring &rhs)
  {
    if (SHOW)
    {
      cout << "in mstring equal operator ";
      cout << rhs;
      cout << endl;
    }
    if (this != &rhs)
    {
      _free();
      allocate_(rhs.gets_()->c_str());
    }
    return *this;
  }

  friend ostream &operator<<(ostream &o, const mstring &rhs)
  {
    if (rhs)
    {
      o << *(rhs.gets_());
    }
    return o;
  }

  operator bool() const { return gets_() ? true : false; }

private:
  // data
#ifdef RAWPOINTER
  string *s_;
#endif
#ifdef UNIQUEPOINTER
  unique_ptr<string> s_;
#endif

  // functions

  void allocate_(const char *s)
  {
    if (s)
    {
#ifdef RAWPOINTER
      s_ = new string(s);
#endif
#ifdef UNIQUEPOINTER
      s_ = make_unique<string>(s);
#endif
    }
  }

  string *gets_() const
  {
#ifdef RAWPOINTER
    return s_;
#endif
#ifdef UNIQUEPOINTER
    return s_.get();
#endif
  }

  void _free()
  {
#ifdef RAWPOINTER
    delete s_;
    s_ = nullptr;
#endif
#ifdef UNIQUEPOINTER
    s_ = nullptr;
#endif
  }
};

/*----------------------------------------------------------------
SSN class
-----------------------------------------------------------------*/
class ssn
{
public:
  ssn(const char *s, const char *n = nullptr, const char *c = nullptr) : ssn_(s), name_(n), country_(c)
  {
    if (SHOW)
    {
      cout << "in ssn constructor " << endl;
    }
  }

  ~ssn()
  {
    if (SHOW)
    {
      cout << "in ssn disstructor " << endl;
    }
  }

  // COPY AND EQUAL OPERATOR NOT WRITTEN AS THIS CLASS HAS NO HEAP OBJECTS ON ITS OWN

  friend ostream &operator<<(ostream &o, const ssn &r)
  {
    o << r.name_ << " " << r.ssn_ << " " << r.country_;
    return o;
  }

private:
  // data
  mstring ssn_;     // 2156789PQ
  mstring name_;    // SSN/Pan etc
  mstring country_; // Country issued
};

/*----------------------------------------------------------------
name class
-----------------------------------------------------------------*/
class name
{
public:
  name(const char *f, const char *l = nullptr, const char *m = nullptr, const char *t = nullptr) : fname_(f), lname_(l), mname_(m), title_(t)
  {
    if (SHOW)
    {
      cout << "in name constructor " << endl;
    }
  }

  ~name()
  {
    if (SHOW)
    {
      cout << "in name disstructor " << endl;
    }
  }

  // COPY AND EQUAL OPERATOR NOT WRITTEN AS THIS CLASS HAS NO HEAP OBJECTS ON ITS OWN

  friend ostream &operator<<(ostream &o, const name &r)
  {
    o << r.fname_ << " " << r.lname_ << " " << r.mname_ << " " << r.title_;
    return o;
  }

private:
  mstring fname_;
  mstring lname_;
  mstring mname_;
  mstring title_;
};

/*----------------------------------------------------------------
date of birth class
-----------------------------------------------------------------*/
class dob
{
public:
  dob(const int m, const int d, const int y) : month_(m), day_(d), year_(y)
  {
    if (SHOW)
    {
      cout << "in dob constructor " << endl;
    }
  }

  ~dob()
  {
    if (SHOW)
    {
      cout << "in dob disstructor " << endl;
    }
  }

  // COPY AND EQUAL OPERATOR NOT WRITTEN AS THIS CLASS HAS NO HEAP OBJECTS ON ITS OWN

  friend ostream &operator<<(ostream &o, const dob &r)
  {
    o << r.month_ << " " << r.day_ << " " << r.year_;
    return o;
  }

private:
  // data
  unsigned int month_;
  unsigned int day_;
  unsigned int year_;
};

/*----------------------------------------------------------------
person class
-----------------------------------------------------------------*/
class person
{
public:
  person(const ssn &s, const name &n, const dob &d, const mstring &p, bool l = true) : ssn_(s), name_(n), _dob(d), _currentp_lace_of_residence(p), _isalive(l)
  {
    if (SHOW)
    {
      cout << "in person constructor " << endl;
    }
  }

  ~person()
  {
    if (SHOW)
    {
      cout << "in person disstructor " << endl;
    }
  }

  // COPY AND EQUAL OPERATOR NOT WRITTEN AS THIS CLASS HAS NO HEAP OBJECTS ON ITS OWN

  friend ostream &operator<<(ostream &o, const person &r)
  {
    o << r.ssn_ << " " << r.name_ << " " << r._dob << " " << r._currentp_lace_of_residence;
    if (!r._isalive)
    {
      o << " Dead ";
    }
    return o;
  }

private:
  // data
  ssn ssn_;
  name name_;
  dob _dob;
  mstring _currentp_lace_of_residence;
  bool _isalive;
};

/*----------------------------------------------------------------
graduate class
-----------------------------------------------------------------*/
class graduate
{
public:
  graduate(const person &p, const mstring &m, int y) : p_(p), degree_awarded_(m), year_(y)
  {
    if (SHOW)
    {
      cout << "in graduate constructor " << endl;
    }
  }
  ~graduate()
  {
    if (SHOW)
    {
      cout << "in graduate disstructor " << endl;
    }
  }

  // COPY AND EQUAL OPERATOR NOT WRITTEN AS THIS CLASS HAS NO HEAP OBJECTS ON ITS OWN

  friend ostream &operator<<(ostream &o, const graduate &r)
  {
    o << r.p_ << " " << r.degree_awarded_ << " " << r.year_;
    return o;
  }

private:
  person p_;
  mstring degree_awarded_;
  int year_;
};

/*----------------------------------------------------------------
graduate class
-----------------------------------------------------------------*/
class list_of_graduates
{
public:
  list_of_graduates(int maxsize = 50) : maxsize_(maxsize), size_(0), list_(nullptr)
  {
    if (SHOW)
    {
      cout << "in list_of_graduates constructor " << endl;
    }
    // WRITE CODE
    list_ = new graduate *[maxsize_];
  }
  ~list_of_graduates()
  {
    if (SHOW)
    {
      cout << "in list_of_graduates disstructor " << endl;
    }
    // WRITE CODE
    for (int i = 0; i < size_; ++i)
    {
      delete list_[i];
    }
    delete[] list_;
    list_ = 0;
    size_ = 0;
  }

  // DO NOT ALLOW TO COPY THIS OBJECT
  list_of_graduates(const list_of_graduates &l) = delete;
  list_of_graduates &operator=(const list_of_graduates &l) = delete;

  void append(const graduate &g)
  {
    // WRITE CODE
    assert(size_ < maxsize_);
    graduate *t = new graduate(g);
    list_[size_++] = t;
  }

  // WRITE cout
  friend ostream &operator<<(ostream &o, const list_of_graduates &r)
  {
    for (int i = 0; i < r.size_; ++i)
    {
      o << *(r.list_[i]) << endl;
    }
    return o;
  }

private:
  int maxsize_;
  int size_;
  graduate **list_;
};

// EOF
