#include "employee.h"

bool employee::show = true;

void employee::setShow(bool value)
{
    show = value;
}

// Constructor
employee::employee(const char *first, const char *last, const char *ssn)
{
    this->name = new char[strlen(first) + 1];
    strcpy(this->name, first);
    this->lastName = new char[strlen(last) + 1];
    strcpy(this->lastName, last);
    this->SSN = new char[strlen(ssn) + 1];
    strcpy(this->SSN, ssn);

    if (show)
    {
        cout << "In employee::employee constructor " << this->name << " " << this->lastName << " " << this->SSN << endl;
    }
}
// Copy constructor
employee::employee(const employee &e)
{
    this->name = new char[strlen(e.name) + 1];
    strcpy(this->name, e.name);
    this->lastName = new char[strlen(e.lastName) + 1];
    strcpy(this->lastName, e.lastName);
    this->SSN = new char[strlen(e.SSN) + 1];
    strcpy(this->SSN, e.SSN);

    if (show)
    {
        cout << "In employee copy constructor " << this->name << " " << this->lastName << " " << this->SSN << endl;
    }
}
// distructor
employee::~employee()
{
    if (show)
    {
        cout << "In employee::~employee distructor " << this->name << " " << this->lastName << " " << this->SSN << endl;
    }
    delete[] this->name;
    delete[] this->lastName;
    delete[] this->SSN;
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
    out << this->name << " " << this->lastName << " " << this->SSN;
    return out;
}
