#include "basepluscommissionemployee.h"

// Constructor and inheriting from commissionemployee
basepluscommissionemployee::basepluscommissionemployee(const char *name, const char *lastName, const char *SSN, const char *company, double commission, const char *baseName, double baseSalary) : commissionemployee(name, lastName, SSN, company, commission)
{
    this->base = new char[strlen(baseName) + 1];
    strcpy(this->base, baseName);
    this->baseSalary = baseSalary;
    if (show)
    {
        cout << "In basepluscommissionemployee::basepluscommissionemployee constructor " << this->name << " " << this->lastName << " " << this->SSN << endl;
        cout << this->company << " " << this->commission << " " << this->base << " " << this->baseSalary << endl;
    }
}

// Copy constructor and inheriting from commissionemployee
basepluscommissionemployee::basepluscommissionemployee(const basepluscommissionemployee &e) : commissionemployee(e)
{
    this->base = new char[strlen(e.base) + 1];
    strcpy(this->base, e.base);
    this->baseSalary = e.baseSalary;
    if (show)
    {
        cout << "In basepluscommissionemployee copy constructor " << this->name << " " << this->lastName << " " << this->SSN << " " << this->company << " " << this->commission << " " << this->base << " " << this->baseSalary << endl;
    }
}

// distructor and inheriting from commissionemployee
basepluscommissionemployee::~basepluscommissionemployee()
{
    if (show)
    {
        cout << "In basepluscommissionemployee::~basepluscommissionemployee distructor " << this->name << " " << this->lastName << endl;
        cout << this->SSN << " " << this->company << " " << this->commission << " " << this->base << " " << this->baseSalary << endl;
    }
    delete[] this->base;
}

// Freind function to print out the base plus commission employee
ostream &operator<<(ostream &out, const basepluscommissionemployee &e)
{
    e.print(out);
    return out;
}

// Print function to print out the base plus commission employee
ostream &basepluscommissionemployee::print(ostream &out) const
{
    out << this->name << " " << this->lastName << " " << this->SSN << " " << this->company << " " << this->commission << " " << this->base << " " << this->baseSalary;
    return out;
}
