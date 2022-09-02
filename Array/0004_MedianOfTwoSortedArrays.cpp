#include "LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int total = nums1.size() + nums2.size(); // total number of two arrays
        if (total % 2 == 0)                      // even number
        {
            int leftNumber  = findKthNumber(nums1, 0, nums2, 0, total / 2);
            int rightNumber = findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
            return (leftNumber + rightNumber) / 2.0;
        }
        else // odd number
            return findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
    }

    int findKthNumber(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
        if (nums1.size() - i > nums2.size() - j) // reverse array if nums1 has more numbers
            return findKthNumber(nums2, j, nums1, i, k);
        if (nums1.size() == i)
            return nums2[j + k - 1];
        if (k == 1)
            return min(nums1[i], nums2[j]);
        int si = min(i + k / 2, (int)nums1.size()), sj = j + k / 2;
        if (nums1[si - 1] > nums2[sj - 1])
        {
            return findKthNumber(nums1, i, nums2, sj, k - k / 2);
        }
        else
        {
            return findKthNumber(nums1, si, nums2, j, k - (si - i));
        }
    }
};
// @lc code=end
