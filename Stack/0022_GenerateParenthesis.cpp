#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
 public:
  vector<string> ans;

  vector<string> generateParenthesis(int n)
  {
    dfs(n, 0, 0, "");
    return ans;
  }

  void dfs(int n, int left_count, int right_count, string seq)
  {
    if (left_count == n && right_count == n) ans.push_back(seq);

    if (left_count < n) dfs(n, left_count + 1, right_count, seq + '(');
    if (right_count < n && right_count < left_count) dfs(n, left_count, right_count + 1, seq + ')');
  }
};
// @lc code=end