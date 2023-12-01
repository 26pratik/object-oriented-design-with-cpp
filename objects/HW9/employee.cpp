#include "employee.h"

bool employee::show = true;

void employee::setShow(bool value)
{
    show = value;
}

// Constructor
employee::employee(const string &first, const string &last, const string &ssn)
{
    name = new string(first);
    lastName = new string(last);
    this->SSN = new string(ssn);

    if (show)
    {
        std::cout << "In employee::employee constructor " << *name << " " << *lastName << " " << *this->SSN << std::endl;
    }
}
// Copy constructor
employee::employee(const employee &e)
{
    name = new string(*e.name);
    lastName = new string(*e.lastName);
    this->SSN = new string(*e.SSN);

    if (show)
    {
        std::cout << "In employee copy constructor " << *name << " " << *lastName << " " << *SSN << std::endl;
    }
}
// distructor
employee::~employee()
{
    if (show)
    {
        std::cout << "In employee::~employee distructor " << *name << " " << *lastName << " " << *SSN << std::endl;
    }
    delete name;
    delete lastName;
    delete SSN;
}
// Friend function
ostream &operator<<(ostream &out, const employee &e)
{
    e.print(out);
    return out;
}
// Print
ostream &employee::print(ostream &out) const
{
    out << *name << " " << *lastName << " " << *SSN;
    return out;
}
