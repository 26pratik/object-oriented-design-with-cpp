#include "commissionemployee.h"

// Inheriting from commissionemployee, adding baseName and baseSalary
class basepluscommissionemployee : public commissionemployee
{
public:
    // constructor
    basepluscommissionemployee(const char *name, const char *lastName, const char *SSN, const char *company, double commission, const char *baseName, double baseSalary);
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
            delete[] this->base;
            this->base = new char[strlen(e.base) + 1];
            strcpy(this->base, e.base);
            this->baseSalary = e.baseSalary;
        }

        if (show)
        {
            cout << "In basepluscommissionemployee equal constructor " << this->name << " " << this->lastName << " " << this->SSN
                 << " " << this->company << " " << this->commission << " " << this->base << " " << this->baseSalary << endl;
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
    char *base;
    double baseSalary;
};
