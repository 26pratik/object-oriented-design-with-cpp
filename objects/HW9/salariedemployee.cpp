#include "salariedemployee.h"

// Constructor and Inheriting from employee
salariedemployee::salariedemployee(const char *first, const char *last, const char *ssn, const char *company, double salary) : employee(first, last, ssn)
{
    this->company = new char[strlen(company) + 1];
    strcpy(this->company, company);
    this->salary = salary;
    if (show)
    {
        cout << "In salariedemployee::salariedemployee constructor " << this->name << " " << this->lastName << " " << this->SSN << " " << this->company << " " << this->salary << endl;
    }
}

// Copy constructor and Inheriting from employee
salariedemployee::salariedemployee(const salariedemployee &e) : employee(e)
{
    this->company = new char[strlen(e.company) + 1];
    strcpy(this->company, e.company);
    this->salary = e.salary;
    if (show)
    {
        cout << "In salariedemployee copy constructor " << this->name << " " << this->lastName << " " << this->SSN << " " << this->company << " " << this->salary << endl;
    }
}

// distructor and Inheriting from employee
salariedemployee::~salariedemployee()
{
    if (show)
    {
        cout << "In salariedemployee::~salariedemployee distructor " << this->name << " " << this->lastName << " " << this->SSN << " " << this->company << " " << this->salary << endl;
    }
    delete[] this->company;
}

// Friend function << overload
ostream &operator<<(ostream &out, const salariedemployee &e)
{
    e.print(out);
    return out;
}

// Print function
ostream &salariedemployee::print(ostream &out) const
{
    out << this->name << " " << this->lastName << " " << this->SSN << " " << this->company << " " << this->salary;
    return out;
}
