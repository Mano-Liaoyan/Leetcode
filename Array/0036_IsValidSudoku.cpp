#include "LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution
{
 public:
  bool isValidSudoku(vector<vector<char>>& board)
  {
    bool status[9];
    // Check row
    for (int i = 0; i < 9; i++)
    {
      memset(status, 0, sizeof(status));
      for (int j = 0; j < 9; j++)
      {
        if (board[i][j] != '.')
        {
          int t = board[i][j] - '1';
          if (status[t]) return false;
          status[t] = true;
        }
      }
    }

    // Check col
    for (int i = 0; i < 9; i++)
    {
      memset(status, 0, sizeof(status));
      for (int j = 0; j < 9; j++)
      {
        if (board[j][i] != '.')
        {
          int t = board[j][i] - '1';
          if (status[t]) return false;
          status[t] = true;
        }
      }
    }

    // Check box
    for (int i = 0; i < 9; i += 3)
    {
      for (int j = 0; j < 9; j += 3)
      {
        memset(status, 0, sizeof(status));
        for (int x = 0; x < 3; x++)
        {
          for (int y = 0; y < 3; y++)
          {
            if (board[i + x][j + y] != '.')
            {
              int t = board[i + x][j + y] - '1';
              if (status[t]) return false;
              status[t] = true;
            }
          }
        }
      }
    }
    return true;
  }
};
// @lc code=end
