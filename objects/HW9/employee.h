#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../util/util.h"

class employee
{
public:
    // constructor
    employee(const string &name, const string &lastName, const string &SSN);
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
            delete name;
            delete lastName;
            delete SSN;
            name = new string(*e.name);
            lastName = new string(*e.lastName);
            SSN = new string(*e.SSN);
        }

        if (show)
        {
            cout << "In employee equal constructor " << *name << " " << *lastName << " " << *SSN << endl;
        }

        return *this;
    }

protected:
    string *name;
    string *lastName;
    string *SSN;
};
#endif