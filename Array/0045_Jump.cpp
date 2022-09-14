#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution
{
 public:
  int jump(vector<int>& nums)
  {
    int n = nums.size();
    vector<int> f(n);

    for (int i = 1, j = 0; i < n; i++)
    {
      while (j + nums[j] < i) j++;
      f[i] = f[j] + 1;
    }

    return f[n - 1];
  }
};
// @lc code=end

int main()
{
  Solution s;
  vector<int> v = {2, 3, 1, 1, 4};
  int res;
  res = s.jump(v);
  cout << res << endl;
  return 0;
}
