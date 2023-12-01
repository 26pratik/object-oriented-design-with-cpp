#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "employee.h"
// company and salary are added to the class, inherited from employee
class salariedemployee : public employee
{
public:
    // constructor
    salariedemployee(const string &name, const string &lastName, const string &SSN, const string &company, double salary);
    // copy constructor
    salariedemployee(const salariedemployee &other);
    // destructor
    virtual ~salariedemployee();
    // Friend function for printing <<
    friend ostream &operator<<(ostream &os, const salariedemployee &emp);
    // Virtual function for printing called by << operator
    virtual ostream &print(ostream &os) const;

    // Equal operator overload and Inheriting from employee
    salariedemployee &operator=(const salariedemployee &e)
    {
        if (this != &e)
        {
            employee::operator=(e);
            delete company;
            company = new string(*e.company);
            salary = e.salary;
        }

        if (show)
        {
            cout << "In salariedemployee equal constructor " << *this->name << " " << *this->lastName << " " << *this->SSN << " " << *this->company << " " << this->salary << endl;
        }

        return *this;
    }

protected:
    string *company;
    double salary;
};

#endif