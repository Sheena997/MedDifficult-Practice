/*
面试题 17.05.  字母与数字
给定一个放有字符和数字的数组，找到最长的子数组，且包含的字符和数字的个数相同。
返回该子数组，若存在多个最长子数组，返回左端点最小的。若不存在这样的数组，返回一个空数组。

示例 1:
输入: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]
输出: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]

示例 2:
输入: ["A","A"]
输出: []

提示：
array.length <= 100000

来源：LeetCode
链接：https://leetcode-cn.com/problems/find-longest-subarray-lcci/
*/
class Solution {
public:
    bool isTheAlpha(string& ret)
    {
        if((ret[0] >= 'a' && ret[0] <= 'z') || (ret[0] >= 'A' && ret[0] <= 'Z'))
            return true;
        return false;
    }
    vector<string> findLongestSubarray(vector<string>& array) {
        vector<string> res;
        unordered_map<int, int> unmp;
        unmp[0] = -1;
        int begin = 0, end = 0, sum = 0;
        
        for(int i = 0; i < array.size(); ++i)
        {
            if(isTheAlpha(array[i]))
                ++sum;
            else
                --sum;
            if(unmp.find(sum) != unmp.end())
            {
                if(i - unmp[sum] > end - begin)
                {
                    begin = unmp[sum] + 1;
                    end = i + 1;
                }
            }
            else
            {
                if(unmp.find(sum) == unmp.end())
                    unmp[sum] = i;
            }
        }
        
        for(int i = begin; i < end; ++i)
            res.push_back(array[i]);
        
        return res;
    }
};