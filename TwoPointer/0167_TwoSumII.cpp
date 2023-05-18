#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution
{
 public:
  vector<int> twoSum(vector<int>& numbers, int target)
  {
    int n = numbers.size();
    for (int l = 0, r = n - 1; l < r; l++)
    {
      while (numbers[l] + numbers[r] > target) r--;
      if (numbers[l] + numbers[r] == target) return {l + 1, r + 1};
    }
    return {};
  }
};
// @lc code=end
