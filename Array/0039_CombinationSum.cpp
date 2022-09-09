#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start

class Solution
{
 public:
  vector<vector<int>> result;
  vector<int> path;

  vector<vector<int>> combinationSum(vector<int>& candidates, int target)
  {
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

    for (int i = 0; candidates[index] * i <= target; i++)
    {
      dfs(candidates, index + 1, target - candidates[index] * i);
      path.push_back(candidates[index]);
    }

    for (int i = 0; candidates[index] * i <= target; i++)
    {
      path.pop_back();
    }

    return;
  }
};

// @lc code=end

int main()
{
  Solution s;
  vector<int> v = {2, 3, 6, 7};
  vector<vector<int>> res;
  res = s.combinationSum(v, 7);
  // cout << s.combinationSum(v, 7) << endl;
  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[i].size(); j++)
    {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
