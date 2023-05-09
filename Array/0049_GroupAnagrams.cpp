#include "../LeetDef.hpp"

using namespace std;

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution
{
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs)
  {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> hash;
    for (auto str : strs)
    {
      string strCopy = str;
      sort(strCopy.begin(), strCopy.end());
      hash[strCopy].push_back(str);
    }

    for (auto item : hash) result.push_back(item.second);

    return result;
  }
};
// @lc code=end
