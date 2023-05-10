#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
 public:
  bool isValid(string s)
  {
    stack<char> stk;
    unordered_map<char, char> dict = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };

    for (auto ch : s)
    {
      if (!dict.count(ch))
        stk.push(ch);
      else if (dict.count(ch))
      {
        if (stk.empty() || stk.top() != dict[ch]) return false;
        stk.pop();
      }
    }
    return stk.empty();
  }
};
// @lc code=end
