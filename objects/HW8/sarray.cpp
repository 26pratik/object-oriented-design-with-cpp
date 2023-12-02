/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
file: sarray.cpp
-----------------------------------------------------------------*/

#include "sarray.h"

bool Sarray::show = false;
unsigned long long Sarray::num_allocated = 0;
unsigned long long Sarray::num_freed = 0;

Sarray::Sarray() : size_(0), ptr_(nullptr)
{
    if (show)
    {
        cout << "Allocating array of size " << size_ << endl;
    }
}

Sarray::Sarray(const Sarray &e) : size_(e.size_), ptr_(new int[e.size_])
{
    copy(e.ptr_, e.ptr_ + e.size_, ptr_);
    if (show)
    {
        cout << "calling copy constructor of size " << size_ << endl;
    }
    ++num_allocated;
    cout << "copy constructor num_allocated=" << num_allocated << endl;
}

Sarray::~Sarray()
{
    if (show)
    {
        cout << "Freeng array of size " << size_ << endl;
    }
    delete[] ptr_;
    if (size_ > 0)
    {
        ++num_freed;
    }
}

Sarray::Sarray(unsigned s) : size_(s), ptr_(s ? new int[s] : nullptr)
{
    if (show)
    {
        cout << "Allocating array of size " << size_ << endl;
    }
    if (s > 0)
    {
        ++num_allocated;
    }
}

Sarray &Sarray::operator=(const Sarray &e)
{
    if (this != &e)
    {
        if (ptr_ != nullptr)
        {
            if (show)
            {
                cout << "Freeng array of size " << size_ << endl;
            }
            delete[] ptr_;
            ++num_freed;
        }

        size_ = e.size_;
        ptr_ = size_ > 0 ? new int[size_] : nullptr;
        copy(e.ptr_, e.ptr_ + size_, ptr_);
        if (show)
        {
            cout << "calling equal pperator of size " << size_ << endl;
        }
        if (size_ > 0)
        {
            ++num_allocated;
            cout << "equal operator num_allocated=" << num_allocated << endl;
        }
    }
    return *this;
}

void Swap(Sarray &sarray1, Sarray &sarray2)
{
    swap(sarray1.size_, sarray2.size_);
    swap(sarray1.ptr_, sarray2.ptr_);
}

#ifdef MOVE

Sarray &Sarray::operator=(Sarray &&e) noexcept
{
    if (this != &e)
    {
        if (ptr_ != nullptr)
        {
            if (show)
            {
                cout << "Freeng array of size " << size_ << endl;
            }
            delete[] ptr_;
            ++num_freed;
        }
        ptr_ = e.ptr_;
        size_ = e.size_;
        e.ptr_ = nullptr;
        e.size_ = 0;
        if (show)
        {
            cout << "calling move equal operator size " << size_ << endl;
            cout << "Nothing freed. Array was taken by move/equal operator" << endl;
        }
    }
    return *this;
}

Sarray::Sarray(Sarray &&e) noexcept : size_(e.size_), ptr_(e.ptr_)
{
    e.size_ = 0;
    e.ptr_ = nullptr;
    if (show)
    {
        cout << "calling move constructor of size " << size_ << endl;
        cout << "Nothing freed. Array was taken by move constructor" << endl;
    }
}
#endif
