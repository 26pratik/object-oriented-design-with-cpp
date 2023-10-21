/*----------------------------------------------------------------
Copyright (c) 2023 Author: Pratik Hariya
file: intmatrix2.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has intmatrix2 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
NOTHING CAM BE ADDED except intmatrix2.h
-----------------------------------------------------------------*/
#include "intmatrix2.h"

/*----------------------------------------------------------------
Definition of routines of intmatrix2 class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Space allocation of static must be in CPP file
-----------------------------------------------------------------*/
bool intmatrix2::_show = false;

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/

intmatrix2::intmatrix2(const intmatrix2 &matrix)
{
    copy__(matrix);
}

intmatrix2::intmatrix2(const string &str) : rows__(0), cols__(0), datapoint__(0), data__(nullptr)
{
    string num;
    vector<int> rows;
    vector<vector<int>> matrix;
    int row = 0;
    int col = 0;
    matrix.resize(row, vector<int>(col, 0));

    for (char c : str)
    {
        if (isdigit(c))
        {
            num += c;
        }
        else if (c == '|' || c == ' ')
        {
            if (!num.empty())
            {
                rows.push_back(stoi(num));
                num = "";
            }

            if (c == '|')
            {
                if (col == 0)
                {
                    col = rows.size();
                }
                else if (rows.size() != col)
                {
                    exit(1);
                }

                matrix.push_back(rows);
                rows.clear();

                row++;
            }
        }
        else
        {
            exit(1);
        }
    }

    if (!num.empty())
    {
        rows.push_back(stoi(num));
    }

    if (col == 0)
    {
        col = rows.size();
    }
    else if (rows.size() != col)
    {
        return;
    }

    matrix.push_back(rows);
    row++;
    rows__ = matrix.size();

    if (rows__ > 0)
    {
        cols__ = matrix[0].size();
    }
    else
    {
        cols__ = 0;
    }

    if (rows__ == 0 || cols__ == 0)
    {
        data__ = nullptr;
        return;
    }

    data__ = new int *[rows__];

    for (int i = 0; i < rows__; i++)
    {
        data__[i] = new int[cols__];

        for (int j = 0; j < cols__; j++)
        {
            data__[i][j] = matrix[i][j];
        }
    }
}

intmatrix2::intmatrix2(const int rows, const int cols, const int datapoint) : rows__(rows), cols__(cols), datapoint__(datapoint), data__(nullptr)
{
    if (rows__ > 0 && cols__ > 0)
    {
        data__ = new int *[rows__];

        for (int i = 0; i < rows__; i++)
        {
            data__[i] = new int[cols__];

            for (int j = 0; j < cols__; j++)
            {
                data__[i][j] = datapoint__;
            }
        }
    }
    else
    {
        data__ = nullptr;
    }
}

intmatrix2 intmatrix2::add(const intmatrix2 &matrix) const
{

    if (rows__ != matrix.rows__ || cols__ != matrix.cols__)
    {
        return intmatrix2();
    }

    intmatrix2 ans(rows__, cols__, 0);

    for (int i = 0; i < rows__; i++)
    {
        for (int j = 0; j < cols__; j++)
        {
            ans.data__[i][j] = data__[i][j] + matrix.data__[i][j];
        }
    }

    return ans;
}

intmatrix2 intmatrix2::mult(const intmatrix2 &matrix) const
{

    if (rows__ == 1 && cols__ == 1)
    {
        intmatrix2 ans(matrix.rows__, matrix.cols__, 0);

        for (int i = 0; i < matrix.rows__; i++)
        {
            for (int j = 0; j < matrix.cols__; j++)
            {
                ans.data__[i][j] = data__[0][0] * matrix.data__[i][j];
            }
        }

        return ans;
    }

    if (matrix.rows__ == 1 && matrix.cols__ == 1)
    {
        intmatrix2 ans(rows__, cols__, 0);

        for (int i = 0; i < rows__; i++)
        {
            for (int j = 0; j < cols__; j++)
            {
                ans.data__[i][j] = data__[i][j] * matrix.data__[0][0];
            }
        }

        return ans;
    }

    if (cols__ != matrix.rows__)
    {
        return intmatrix2();
    }

    intmatrix2 ans(rows__, matrix.cols__, 0);

    for (int i = 0; i < rows__; i++)
    {
        for (int j = 0; j < matrix.cols__; j++)
        {
            for (int k = 0; k < cols__; k++)
            {
                ans.data__[i][j] += data__[i][k] * matrix.data__[k][j];
            }
        }
    }

    return ans;
}

void intmatrix2::copy__(const intmatrix2 &matrix)
{
    rows__ = matrix.rows__;
    cols__ = matrix.cols__;
    datapoint__ = matrix.datapoint__;

    if (rows__ > 0 && cols__ > 0)
    {
        data__ = new int *[rows__];

        for (int i = 0; i < rows__; i++)
        {
            data__[i] = new int[cols__];

            for (int j = 0; j < cols__; j++)
            {
                data__[i][j] = matrix.data__[i][j];
            }
        }
    }
}

void intmatrix2::release__()
{
    if (data__ != nullptr)
    {
        for (int i = 0; i < rows__; i++)
        {
            delete[] data__[i];
        }

        delete[] data__;
    }
}

void intmatrix2::print__()
{
    if (data__ == nullptr)
    {
        cout << "   Empty Matrix    " << endl;
        return;
    }

    for (int i = 0; i < rows__; i++)
    {
        for (int j = 0; j < cols__; j++)
        {
            cout << data__[i][j] << " ";
        }

        cout << endl;
    }
}

bool intmatrix2::isEqual(const intmatrix2 &matrix) const
{
    if (data__ == nullptr && matrix.data__ == nullptr)
    {
        return true;
    }

    if (rows__ != matrix.rows__ || cols__ != matrix.cols__)
    {
        return false;
    }

    for (int i = 0; i < rows__; i++)
    {
        for (int j = 0; j < cols__; j++)
        {
            if (data__[i][j] != matrix.data__[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

ostream &operator<<(ostream &os, const intmatrix2 &matrix)
{

    if (matrix.rows__ == 0 || matrix.cols__ == 0)
    {
        os << "     Empty Matrix    " << endl;
        return os;
    }

    for (int i = 0; i < matrix.rows__; i++)
    {
        for (int j = 0; j < matrix.cols__; j++)
        {
            os << matrix.data__[i][j] << " ";
        }

        os << endl;
    }

    return os;
}

intmatrix2 &intmatrix2::operator=(const intmatrix2 &matrix)
{
    if (this != &matrix)
    {
        release__();
        copy__(matrix);
    }

    return *this;
}

intmatrix2::~intmatrix2()
{
    release__();
}

// EOF
