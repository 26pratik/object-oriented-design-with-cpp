#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../util/util.h"

class employee
{
public:
    // constructor
    employee(const char *name, const char *lastName, const char *SSN);
    // copy constructor
    employee(const employee &other);
    // destructor
    virtual ~employee();
    // Friend function for printing <<
    friend ostream &operator<<(ostream &os, const employee &emp);
    // Virtual function for printing called by << operator
    virtual ostream &print(ostream &os) const;
    static bool show;
    static void setShow(bool value); // static member function

    // Equal operator overload
    virtual employee &operator=(const employee &e)
    {
        if (this != &e)
        {
            delete[] this->name;
            delete[] this->lastName;
            delete[] this->SSN;
            this->name = new char[strlen(e.name) + 1];
            strcpy(this->name, e.name);
            this->lastName = new char[strlen(e.lastName) + 1];
            strcpy(this->lastName, e.lastName);
            this->SSN = new char[strlen(e.SSN) + 1];
            strcpy(this->SSN, e.SSN);
        }

        // Add company and salary
        if (show)
        {
            cout << "In employee equal constructor " << this->name << " " << this->lastName << " " << this->SSN << endl;
        }

        return *this;
    }

protected:
    char *name;
    char *lastName;
    char *SSN;
};
#endif