/*----------------------------------------------------------------
Copyright (c) 2023 Author: Pratik Hariya
file: L0006.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
6. Zigzag Conversion
https://leetcode.com/problems/zigzag-conversion/
---------------------------------------------------------------- - */

/*----------------------------------------------------------------
NO  includes here
CUT AND PASTE whole file in Leetcode
-----------------------------------------------------------------*/
/*----------------------------------------------------------------
WRITE CLASS L0006
-----------------------------------------------------------------*/
/*----------------------------------------------------------------
Declaration of L0006 class
-----------------------------------------------------------------*/

class L0006
{
public:
  // WRITE CODE
  L0006(const string &s, int numRows, string &ans, bool show) : s_(s), r_(numRows), ans_(ans), show_(show)
  {
    alg_();
  }

private:
  // inputs
  const string &s_;
  const int r_;
  string &ans_;
  bool show_;
  // all private routines
  void alg_();
};

/*----------------------------------------------------------------
Time: THETA(n)
Space O(n*r)
-----------------------------------------------------------------*/
void L0006::alg_()
{
  // WRITE CODE
  vector<vector<char>> matrix(r_, vector<char>(s_.size(), '\0'));
  int row = 0, col = 0;
  bool vertical = true;

  cout << s_ << endl;
  cout << "num rows = " << r_ << endl;

  if (r_ == 1)
  {
    ans_ = s_;
    return;
  }

  for (char c : s_)
  {
    cout << row << " ";
    matrix[row][col] = c;
    if (vertical)
    {
      if (row == r_ - 1)
      {
        row--;
        col++;
        vertical = false;
      }
      else
      {
        row++;
      }
    }
    else
    {
      if (row == 0)
      {
        row++;
        vertical = true;
      }
      else
      {
        row--;
        col++;
      }
    }
  }

  cout << endl;

  for (int i = 0; i < r_; i++)
  {
    for (int j = 0; j < s_.size(); j++)
    {
      if (matrix[i][j] != '\0')
      {
        cout << matrix[i][j];
        ans_ += matrix[i][j];
      }
    }
    cout << endl;
  }

  cout << ans_ << endl;
}

/*----------------------------------------------------------------
Leetcode interface
NPTHING CAN BE CHANGED BELOW
This procedure must be at the end
-----------------------------------------------------------------*/
class Solution
{
public:
  string convert(string s, int numRows)
  {
    string ans;
    bool show = false;
    L0006 a(s, numRows, ans, show);
    return ans;
  }
};
