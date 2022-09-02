#include "LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int currentPointer = 1, newPointer = 0;
    int counter = 1;
    while (currentPointer < nums.size()) {
      if (nums[currentPointer] == nums[newPointer])
        currentPointer++;
      else {
        nums[++newPointer] = nums[currentPointer++];
        counter++;
      }
    }
    return counter;
  }
};
// @lc code=end
