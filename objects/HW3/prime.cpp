/*----------------------------------------------------------------
Copyright (c) 2023 Author: Pratik Hariya
file: prime.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has prime class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "prime.h"

/*----------------------------------------------------------------
Definition of routines of prime class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Space allocation of static must be in CPP file
-----------------------------------------------------------------*/
unsigned long long  prime::kount = 0ll;

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
prime::prime(vector<int>& v, const string& algname, int n) :v_(v), algname_(algname), n_(n) {
    if(algname_ == "upto_n_minus_1") {
        upto_n_minus_1_();
    } else if(algname_ == "upto_n_by_2") {
        upto_n_by_2_();
    } else if(algname_ == "sqrt_of_n") {
        sqrt_of_n_();
    } else if(algname_ == "upto_prime") {
        upto_prime_();
    } else if(algname_ == "sieve_of_eratosthenes") {
        sieve_of_eratosthenes_();
    }
} 

prime::~prime() {

}

bool prime::is_prime_upto_n_minus_1_(int n) {
    for(int i = 2; i < n; ++i) {
        incr_kount();
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void prime::upto_n_minus_1_() {
    v_.push_back(2);
    for(int i=3; i<=n_; i = i + 2) {
        incr_kount();
        if(is_prime_upto_n_minus_1_(i)) {
            v_.push_back(i);
        }
    }
}

bool prime::is_prime_upto_n_by_2_(int n) {
    for(int i = 2; i < n/2; ++i) {
        incr_kount();
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void prime::upto_n_by_2_() {
    v_.push_back(2);
    for(int i = 3; i <= n_; i = i + 2) {
        incr_kount();
        if(is_prime_upto_n_by_2_(i)) {
            v_.push_back(i);
        }
    }
}

bool prime::is_prime_sqrt_of_n_(int n) {
    for(int i = 2; (i * i) <= n; ++i) {
        incr_kount();
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

void prime::sqrt_of_n_() {
    v_.push_back(2);
    for(int i = 3; i <= n_; i = i + 2) {
        incr_kount();
        if(is_prime_sqrt_of_n_(i)) {
            v_.push_back(i);
        }
    }
}

bool prime::is_divisible_by_prime_(const vector<int>& pa, int n) {
    for(int i = 0; (pa[i] * pa[i]) <= n; ++i) {
        incr_kount();
        if(n % pa[i] == 0) {
            return false;
        }
    }
    return true;
}

void prime::upto_prime_() {
    v_.push_back(2);
    for(int i = 3; i <= n_; i = i + 2) {
        incr_kount();
        if(is_divisible_by_prime_(v_,i)) {
            v_.push_back(i);
        }
    }    
}

void prime::sieve_of_eratosthenes_() {
#if 0
    vector<bool> l;
    for(int i = 0; i < n_+1; ++i) {
        incr_kount();
        l.push_back(true);
    }
#endif
#if 1
    vector<bool> l(n_ + 1, true);
#endif
    l[0] = false;
    l[1] = false;
    int i = 2;
    while((i * i) <= n_) {
        if(l[i] == true) {
            for(int j = i; ((i * j) < (n_ + 1)); ++j) {
                incr_kount();
                l[i+j] = false;
            }
        }
        ++i;
    }

    for(int i = 0; i < n_; ++i) {
        incr_kount();
        if(l[i] == true) {
            v_.push_back(i);
        }
    }
}
//EOF

