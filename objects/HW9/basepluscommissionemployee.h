#include "commissionemployee.h"

// Inheriting from commissionemployee, adding baseName and baseSalary
class basepluscommissionemployee : public commissionemployee
{
public:
    // constructor
    basepluscommissionemployee(const string &name, const string &lastName, const string &SSN, const string &company, double commission, const string &baseName, double baseSalary);
    // copy constructor
    basepluscommissionemployee(const basepluscommissionemployee &other);
    // destructor
    virtual ~basepluscommissionemployee();
    // Friend function for printing <<
    friend ostream &operator<<(ostream &os, const basepluscommissionemployee &emp);
    // Virtual function for printing called by << operator
    virtual ostream &print(ostream &os) const;

    // Equal operator overload and inheriting from commissionemployee
    basepluscommissionemployee &operator=(const basepluscommissionemployee &e)
    {
        if (this != &e)
        {

            commissionemployee::operator=(e);
            delete base;
            base = new string(*e.base);
            baseSalary = e.baseSalary;
        }

        if (show)
        {
            cout << "In basepluscommissionemployee equal constructor " << *this->name << " " << *this->lastName << " " << *this->SSN 
            << " " << *this->company << " " << this->commission << " " << *this->base << " " << this->baseSalary << endl;
        }

        return *this;
    }

    employee &operator=(const employee &other)
    {
        const auto *ptr = dynamic_cast<const basepluscommissionemployee *>(&other);
        if (ptr != nullptr)
        {
            *this = *ptr;
        }
        return *this;
    }

protected:
    string *base;
    double baseSalary;
};
