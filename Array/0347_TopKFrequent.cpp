#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
 public:
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    unordered_map<int, int> umap;
    for (auto num : nums) umap[num]++;
    priority_queue<pair<int, int>> heap;
    for (auto item : umap) heap.push({item.second, item.first});
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
      res.push_back(heap.top().second);
      heap.pop();
    }
    return res;
  }
};
// @lc code=end
