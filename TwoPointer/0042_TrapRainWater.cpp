#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
 public:
  int trap(vector<int>& height)
  {
    if (height.empty()) return 0;
    int n = height.size(), res = 0;
    vector<int> left(n + 1), right(n + 1);
    left[0] = height[0];
    right[n - 1] = height[n - 1];  // 最边界的不能存水
    for (int i = 1; i < n; i++)
    {
      left[i] = max(left[i - 1], height[i]);  // 计算i左边最高的柱子有多高
    }
    for (int i = n - 2; i >= 0; i--)
    {
      right[i] = max(right[i + 1], height[i]);  // 计算右边的
    }
    for (int i = 0; i < n; i++)
    {
      res += min(left[i], right[i]) - height[i];  // 存水的高度取决于较小的柱子
    }
    return res;
  }
};
// @lc code=end
