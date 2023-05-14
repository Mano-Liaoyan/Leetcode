#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures)
  {
    vector<int> answer(temperatures.size());
    stack<int> stk;
    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
      while (stk.size() && temperatures[i] >= temperatures[stk.top()]) stk.pop();
      if (stk.size()) answer[i] = stk.top() - i;
      stk.push(i);
    }
    return answer;
  }
};
// @lc code=end
