/*----------------------------------------------------------------
Copyleft (c) 2023 Author: Jagadeesh Vasudevamurthy
file: p2.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has p2 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
YOU CANNOT INCLUDE ANY OTHER FILES
-----------------------------------------------------------------*/
#include "p2.h"

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
int p2::d1(int n, char charToPrint)
{

    string c;
    c += charToPrint;
    c += " ";

    int s, i, j;
    int k = 0;
    int index = n + (n - 1);

    for (int in = 0; in < index; in++)
    {
        cout << in;
    }
    cout << "\n";

    for (i = 1; i <= n; i++)
    {
        for (s = i; s < n; s++)
        {
            cout << " ";
        }

        for (j = 1; j <= i; j++)
        {
            cout << c;
            k++;
        }

        // ending line after each row
        cout << "\n";
    }
    cout << "N = " << n << " Number of " << c << " = " << k << endl;
    return k;
}

int p2::d2(int n, char charToPrint)
{

    string c;
    c += charToPrint;
    c += " ";

    int s, i, j;
    int k = 0;
    int index = n + (n - 1);

    for (int in = 0; in < index; in++)
    {
        cout << in;
    }
    cout << "\n";
    for (i = n; i >= 1; i--)
    {
        for (s = i; s < n; s++)
        {
            cout << " ";
        }

        for (j = 1; j <= i; j++)
        {
            cout << c;
            k++;
        }
        cout << "\n";
    }
    cout << "N = " << n << " Number of " << c << " = " << k << endl;

    return k;
}

int p2::d3(int n, char charToPrint)
{

    string c;
    c += charToPrint;
    c += " ";

    int j1, j2;
    int k = 0;
    int index = n;
    int mid = (n - 1) / 2;
    int temp = 2;

    for (int in = 0; in < index; in++)
    {
        cout << in;
    }
    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        if (i <= mid)
        {
            j1 = mid + i;
            j2 = mid - i;
        }
        else
        {
            j1 = mid - i + temp;
            j2 = mid + i - temp;
            temp = temp + 2;
        }
        for (int j = 0; j < n; j++)
        {
            if (j == j1 || j == j2)
            {
                cout << c;
                k++;
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
    cout << "N = " << n << " Number of " << c << " = " << k << endl;
    return k;
}
int p2::d4(int n, char charToPrint)
{

    string c;
    c += charToPrint;
    int k = 0;
    int index = n;
    int rows = n + (n - 1);
    int mid = (rows - 1) / 2;
    int numOfStars = 0;

    for (int in = 0; in < index; in++)
    {
        cout << in;
    }
    cout << "\n";
    for (int i = 0; i < rows; i++)
    {
        if (i <= mid)
        {
            numOfStars++;
        }
        else
        {
            numOfStars--;
        }
        for (int j = 0; j < numOfStars; j++)
        {
            cout << c;
            k++;
        }
        cout << "\n";
    }

    cout << "N = " << n << " Number of " << c << " = " << k << endl;
    return k;
}
int p2::d5(int n, char charToPrint)
{
    string c;
    c += charToPrint;
    int k = 0;
    int index = n;
    int rows = n + (n - 1);
    int mid = (rows - 1) / 2;
    int numOfStars = 0;

    for (int in = 0; in < index; in++)
    {
        cout << in;
    }
    cout << "\n";
    for (int i = 0; i < rows; i++)
    {
        if (i <= mid)
        {
            numOfStars++;
        }
        else
        {
            numOfStars--;
        }
        for (int s = 0; s < n - numOfStars; s++)
        {
            cout << " ";
        }
        for (int j = 0; j < numOfStars; j++)
        {
            cout << c;
            k++;
        }
        cout << "\n";
    }

    cout << "N = " << n << " Number of " << c << " = " << k << endl;
    return k;
}
int p2::d6(int n, char charToPrint)
{

    string c;
    c += charToPrint;
    c += " ";
    int k = 0;
    int index = n + (n - 1);
    int numOfStars = n;
    int rows = n + (n - 1);
    int mid = (rows - 1) / 2;

    for (int in = 0; in < index; in++)
    {
        cout << in;
    }
    cout << "\n";
    for (int i = 0; i <= rows; i++)
    {
        if (i <= mid)
        {
            numOfStars--;
        }
        else if (i > mid + 1)
        {
            numOfStars++;
        }

        for (int s = 0; s < n - 1 - numOfStars; s++)
        {
            cout << " ";
        }
        for (int j = 0; j <= numOfStars; j++)
        {
            cout << c;
            k++;
        }
        cout << "\n";
    }
    cout << "N = " << n << " Number of " << c << " = " << k << endl;
    return k;
}

void p2::riceOnChessBoard(int n)
{
    // 2^n-1

    unsigned long long int totalSum = 0;
    unsigned long long int value = 0;

    for (int i = 0; i < n; i++)
    {
        value = pow(2, i);
        cout << "Rice on Square " << i + 1 << " = " << value << endl;
        totalSum += value;
    }
    cout << "Total rice = " << totalSum << endl;
    cout << "Total rice must be = 18446744073709551615 " << endl;
}

// EOF
