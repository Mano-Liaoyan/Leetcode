#include "LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
 public:
  bool row[9][9], col[9][9], cell[3][3][9];

  void solveSudoku(vector<vector<char>>& board)
  {
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    memset(cell, 0, sizeof cell);

    // Read in the exising numbers
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        if (board[i][j] != '.')
        {
          int value = board[i][j] - '1';
          row[i][value] = col[j][value] = cell[i / 3][j / 3][value] = true;
        }
      }
    }
    dfs(board, 0, 0);
  }

  bool dfs(vector<vector<char>>& board, int x, int y)
  {
    if (y == 9) x++, y = 0;
    if (x == 9) return true;

    if (board[x][y] != '.') return dfs(board, x, y + 1);
    for (int value = 0; value < 9; value++)
    {
      if (!row[x][value] && !col[y][value] && !cell[x / 3][y / 3][value])
      {
        board[x][y] = value + '1';
        row[x][value] = col[y][value] = cell[x / 3][y / 3][value] = true;
        if (dfs(board, x, y + 1)) return true;
        board[x][y] = '.';
        row[x][value] = col[y][value] = cell[x / 3][y / 3][value] = false;
      }
    }
    return false;
  }
};
// @lc code=end
