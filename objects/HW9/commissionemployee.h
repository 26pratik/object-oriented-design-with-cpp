#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include "employee.h"

// Inheriting from employee, adding commissionAmount and commissionName
class commissionemployee : public employee
{
public:
    // constructor
    commissionemployee(const string &name, const string &lastName, const string &SSN, const string &company, double commission);
    // copy constructor
    commissionemployee(const commissionemployee &other);
    // destructor
    virtual ~commissionemployee();
    // Friend function for printing <<
    friend ostream &operator<<(ostream &os, const commissionemployee &emp);
    // Virtual function for printing called by << operator
    virtual ostream &print(ostream &os) const;

    // Equal operator overload and inheriting from employee
    commissionemployee &operator=(const commissionemployee &e)
    {
        if (this != &e)
        {
            employee::operator=(e);
            delete company;
            company = new string(*e.company);
            commission = e.commission;
        }

        // Add salary
        if (show)
        {
            cout << "In commissionemployee equal constructor " << *this->name << " " << *this->lastName << " " << *this->SSN
                 << " " << *this->company << " " << this->commission << std::endl;
        }

        return *this;
    }

    employee &operator=(const employee &other)
    {
        const auto *ptr = dynamic_cast<const commissionemployee *>(&other);
        if (ptr != nullptr)
        {
            *this = *ptr;
        }
        return *this;
    }

protected:
    string *company;
    double commission;
};

#endif