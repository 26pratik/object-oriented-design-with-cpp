/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
file: sarray.h
-----------------------------------------------------------------*/
#pragma once

#include "../util/util.h"

#define T int

#define MOVE

class Sarray
{
public:
	Sarray();
	Sarray(const Sarray &e);
	~Sarray();
	Sarray(unsigned size);
	Sarray &operator=(const Sarray &e);
	friend void Swap(Sarray &sarray1, Sarray &sarray2);
	static unsigned long long num_freed;
	static unsigned long long num_allocated;
	static bool show;

#ifdef MOVE
	Sarray &operator=(Sarray &&other) noexcept;
	Sarray(Sarray &&other) noexcept;
#endif

private:
	unsigned size_;
	T *ptr_;
};
