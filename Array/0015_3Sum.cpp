#include "LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    // Sort the array
    sort(nums.begin(), nums.end());
    // First layer pointer
    for (int i = 0; i < nums.size(); i++) {
      // If i is not the first one and the continued number is the same, pass
      if (i && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
        // If j is not the first one and the continued number is the same, pass
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        // Q: Why k - 1? A: The next smaller amount
        while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0)
          k--;
        if (nums[i] + nums[j] + nums[k] == 0)
          result.push_back({nums[i], nums[j], nums[k]});
      }
    }
    return result;
  }
};
// @lc code=end
