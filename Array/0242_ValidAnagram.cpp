#include "../LeetDef.hpp"
using namespace std;

/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution
{
 public:
  // Default solution
  // bool isAnagram(string s, string t)
  // {
  //   if (s.size() != t.size()) return false;

  //   unordered_map<char, int> smap;
  //   for (auto i : s) smap[i]++;
  //   for (auto j : t)
  //   {
  //     smap[j]--;
  //     if (smap[j] < 0) return false;
  //   }

  //   return true;
  // }
  // Optimized Solution
  bool isAnagram(string s, string t)
  {
    if (s.size() != t.size()) return false;

    int arr[26] = {0};

    for (auto i : s) arr[i - 'a']++;
    for (auto j : t)
    {
      arr[j - 'a']--;
      if (arr[j - 'a'] < 0) return false;
    }

    return true;
  }
};
// @lc code=end
