/*
面试题 16.24. 数对和
设计一个算法，找出数组中两数之和为指定值的所有整数对。一个数只能属于一个数对。

示例 1:

输入: nums = [5,6,5], target = 11
输出: [[5,6]]
示例 2:

输入: nums = [5,6,5,6], target = 11
输出: [[5,6],[5,6]]
提示：

nums.length <= 100000

来源：LeetCode
链接：https://leetcode-cn.com/problems/pairs-with-sum-lcci/
*/
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> res;
        unordered_map<int, int> unmp;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(unmp[target - nums[i]] != 0)
            {
                res.push_back({target - nums[i], nums[i]});
                --unmp[nums[i]];
                --unmp[target - nums[i]];
            }
            ++unmp[nums[i]];
        }
        
        return res;
    }
};


   