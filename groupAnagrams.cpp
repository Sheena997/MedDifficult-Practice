/*
面试题 10.02. 变位词组
编写一种方法，对字符串数组进行排序，将所有变位词组合在一起。
变位词是指字母相同，但排列不同的字符串。

注意：本题相对原题稍作修改

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：LeetCode
链接：https://leetcode-cn.com/problems/group-anagrams-lcci/
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> unmp;
        vector<vector<string>> res;
        
        for(int i = 0; i < strs.size(); ++i)
        {
            string ret = strs[i];
            sort(ret.begin(), ret.end());
            unmp[ret].push_back(strs[i]);
        }
        
        for(auto e : unmp)
        {
            res.push_back(e.second);
        }
        
        return res;
    }
};