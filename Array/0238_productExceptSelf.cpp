#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
 public:
  vector<int> productExceptSelf(vector<int>& nums)
  {
    int n = nums.size();
    vector<int> answer(n);

    answer[0] = 1;
    for (int i = 1; i < n; i++) answer[i] = answer[i - 1] * nums[i - 1];

    int R = 1;
    for (int i = n - 1; i >= 0; i--)
    {
      answer[i] *= R;
      R *= nums[i];
    }
    return answer;
  }
};
// @lc code=end
