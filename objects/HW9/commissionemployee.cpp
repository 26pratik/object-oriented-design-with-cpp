#include "commissionemployee.h"

// Constructor and inheriting from employee
commissionemployee::commissionemployee(const char *first, const char *last, const char *ssn, const char *company, double commission) : employee(first, last, ssn)
{
    this->company = new char[strlen(company) + 1];
    strcpy(this->company, company);
    this->commission = commission;
    if (show)
    {
        cout << "In commissionemployee::commissionemployee constructor " << this->name << " " << this->lastName << " " << this->SSN << " " << this->company << " " << this->commission << endl;
    }
}

// Copy constructor and inheriting from employee
commissionemployee::commissionemployee(const commissionemployee &e) : employee(e)
{
    this->company = new char[strlen(e.company) + 1];
    strcpy(this->company, e.company);
    this->commission = e.commission;
    if (show)
    {
        cout << "In commissionemployee copy constructor " << this->name << " " << this->lastName << " " << this->SSN << " " << this->company << " " << this->commission << endl;
    }
}

// distructor and inheriting from employee
commissionemployee::~commissionemployee()
{
    if (show)
    {
        cout << "In commissionemployee::~commissionemployee distructor " << this->name << " " << this->lastName << " " << this->SSN << " " << this->company << " " << this->commission << endl;
    }
    delete[] this->company;
}

// Freind function to print out the commission employee
ostream &operator<<(ostream &out, const commissionemployee &e)
{
    e.print(out);
    return out;
}

// Print function to print out the commission employee
ostream &commissionemployee::print(ostream &out) const
{
    out << this->name << " " << this->lastName << " " << this->SSN << " " << this->company << " " << this->commission;
    return out;
}