#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution
{
 public:
  int longestConsecutive(vector<int>& nums)
  {
    unordered_set<int> uset;
    for (auto num : nums) uset.insert(num);

    int longestConsecutive = 0;

    for (auto num : uset)
    {
      if (!uset.count(num - 1))
      {
        int currentNum = num;
        int currentConsecutive = 1;

        while (uset.count(currentNum + 1)) currentNum++, currentConsecutive++;

        longestConsecutive = max(longestConsecutive, currentConsecutive);
      }
    }
    return longestConsecutive;
  }
};
// @lc code=end
