#include "LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
 public:
  vector<int> searchRange(vector<int>& nums, int target)
  {
    if (nums.empty()) return {-1, -1};
    int l = 0, r = nums.size() - 1;
    int upper = -1, lower = -1;
    // Find upperbound
    while (l < r)
    {
      int mid = l + r >> 1;
      if (nums[mid] >= target)
        r = mid;
      else
        l = mid + 1;
    }
    // Find lowerbound
    if (nums[l] == target)
    {
      upper = l;
      while (l + 1 < nums.size() && nums[l + 1] == target) l++;
      lower = l;
      return {upper, lower};
    }
    return {-1, -1};
  }
};
// @lc code=end
