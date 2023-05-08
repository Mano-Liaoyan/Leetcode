#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution
{
 public:
  bool containsDuplicate(vector<int>& nums)
  {
    unordered_map<int, int> umap;
    for (auto i : nums) umap[i]++;
    for (auto i : umap)
      if (i.second >= 2) return true;
    return false;
  }
};
// @lc code=end
