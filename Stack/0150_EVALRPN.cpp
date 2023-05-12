#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
 public:
  int evalRPN(vector<string>& tokens)
  {
    stack<int> stk;
    unordered_set<string> uset = {"+", "-", "*", "/"};
    for (string& token : tokens)
    {
      if (!uset.count(token))
        stk.push(atoi(token.c_str()));
      else
      {
        int num1 = stk.top();
        stk.pop();
        int num2 = stk.top();
        stk.pop();
        switch (token[0])
        {
          case '+':
            stk.push(num1 + num2);
            break;
          case '-':
            stk.push(num2 - num1);
            break;
          case '*':
            stk.push(num1 * num2);
            break;
          case '/':
            stk.push(num2 / num1);
            break;
        }
      }
    }
    return stk.top();
  }
};

// @lc code=end

int main()
{
  vector<string> tokens = {"4", "13", "5", "/", "+"};
  Solution s;
  int res = s.evalRPN(tokens);
  cout << "res:" << res << endl;
  return 0;
}
