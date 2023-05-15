#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=853 lang=cpp
 *
 * [853] 车队
 */

// @lc code=start
class Solution
{
 public:
  int carFleet(int target, vector<int>& position, vector<int>& speed)
  {
    int n = position.size();
    vector<int> id(n);
    for (int i = 0; i < n; i++) id[i] = i;
    sort(id.begin(), id.end(), [&](int a, int b) { return position[a] < position[b]; });

    int res = n;
    double last = 0;

    for (int i = n - 1; i >= 0; i--)
    {
      auto t = (target - position[id[i]]) / (double)speed[id[i]];
      if (t <= last)
        res--;
      else
        last = t;
    }
    return res;
  }
};
// @lc code=end
