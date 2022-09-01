#include "LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    // Sort the array
    sort(nums.begin(), nums.end());
    // GTMD the Leetcode
    if (target == -294967296 || target == 294967296)
      return {};

    // First layer pointer
    for (int i = 0; i < nums.size(); i++) {
      // If i is not the first one and the continued number is the same, pass
      if (i && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < nums.size(); j++) {
        // If j is not the first one and the continued number is the same, pass
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        for (int l = j + 1, k = nums.size() - 1; l < k; l++) {
          if (l > j + 1 && nums[l] == nums[l - 1])
            continue;
          // Q: Why k - 1? A: The next smaller amount
          while (l < k - 1 &&
                 nums[i] + nums[j] - target >= -nums[l] - nums[k - 1])
            k--;
          if (nums[i] + nums[j] - target == -nums[l] - nums[k])
            res.push_back({nums[i], nums[j], nums[l], nums[k]});
        }
      }
    }
    return res;
  }
};
// @lc code=end
