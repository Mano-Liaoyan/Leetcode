#include "LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    pair<int, int> res(INT_MAX, INT_MAX);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (i && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= target)
          k--;
        int sum = nums[i] + nums[j] + nums[k];
        res = min(res, make_pair(abs(sum - target), sum));
        if (j < k - 1) {
          sum = nums[i] + nums[j] + nums[k - 1];
          res = min(res, make_pair(target - sum, sum));
        }
      }
    }
    return res.second;
  }
};
// @lc code=end
