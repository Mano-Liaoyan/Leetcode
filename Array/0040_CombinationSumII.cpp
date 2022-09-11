#include "LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start

class Solution
{
  vector<vector<int>> result;
  vector<int> path;

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, target);
    return result;
  }

  void dfs(vector<int>& candidates, int index, int target)
  {
    if (target == 0)
    {
      result.push_back(path);
      return;
    }

    if (index == candidates.size()) return;

    int k = index + 1;
    while (k < candidates.size() && candidates[k] == candidates[index]) k++;
    int counter = k - index;

    for (int i = 0; candidates[index] * i <= target && i <= counter; i++)
    {
      dfs(candidates, k, target - candidates[index] * i);
      path.push_back(candidates[index]);
    }

    for (int i = 0; candidates[index] * i <= target && i <= counter; i++)
    {
      path.pop_back();
    }

    return;
  }
};
// @lc code=end
