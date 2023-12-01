#include "basepluscommissionemployee.h"

// Constructor and inheriting from commissionemployee
basepluscommissionemployee::basepluscommissionemployee(const string &name, const string &lastName, const string &SSN, const string &company, double commission, const string &baseName, double baseSalary) : commissionemployee(name, lastName, SSN, company, commission)
{
    base = new string(baseName);
    this->baseSalary = baseSalary;
    if (show)
    {
        cout << "In basepluscommissionemployee::basepluscommissionemployee constructor " << *this->name << " " << *this->lastName << " " << *this->SSN << std::endl;
        std::cout << *this->company << " " << this->commission << " " << *this->base << " " << this->baseSalary << endl;
    }
}

// Copy constructor and inheriting from commissionemployee
basepluscommissionemployee::basepluscommissionemployee(const basepluscommissionemployee &e) : commissionemployee(e)
{
    base = new string(*e.base);
    this->baseSalary = e.baseSalary;
    if (show)
    {
        cout << "In basepluscommissionemployee copy constructor " << *this->name << " " << *this->lastName << " " << *this->SSN
             << " " << *this->company << " " << this->commission << " " << *this->base << " " << this->baseSalary << endl;
    }
}

// distructor and inheriting from commissionemployee
basepluscommissionemployee::~basepluscommissionemployee()
{
    if (show)
    {
        cout << "In basepluscommissionemployee::~basepluscommissionemployee distructor " << *this->name << " " << *this->lastName << endl;
        std::cout << *this->SSN << " " << *this->company << " " << this->commission << " " << *this->base << " " << this->baseSalary << endl;
    }
    delete base;
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
    out << *this->name << " " << *this->lastName << " " << *this->SSN << " " << *this->company << " " << this->commission << " " << *this->base << " " << this->baseSalary;
    return out;
}
