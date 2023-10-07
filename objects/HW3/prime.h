/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: prime.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has prime  class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#pragma once

#include "../util/util.h"


/*----------------------------------------------------------------
Declaration of prime class
-----------------------------------------------------------------*/
class prime {
public:
  //WRITE CODE HERE
  prime(vector<int>& v, const string& algname_, int n = 2);
  ~prime();
  static void incr_kount() { ++kount; }
  static void reset_kount() { kount = 0; }
  static unsigned long long get_kount()  { return kount; }

private:
  //Cannot change next 3 lines
  //Data structure is fixed
  static unsigned long long  kount ;
  vector<int>& v_;
  const string& algname_;
  int n_;
  //Must implement 5 functions
  //Cannot change below
  void upto_n_minus_1_();
  void upto_n_by_2_();
  void sqrt_of_n_();
  void upto_prime_();
  void sieve_of_eratosthenes_();
  //You can have any number of private functions and variables below
  bool is_prime_sqrt_of_n_(int n);
  bool is_prime_upto_n_minus_1_(int n);
  bool is_prime_upto_n_by_2_(int n);
  bool is_divisible_by_prime_(const vector<int>& pa, int n);
  //Write code below
};




//EOF

