/*
462. 最少移动次数使数组元素相等 II
给定一个非空整数数组，找到使所有数组元素相等所
需的最小移动数，其中每次移动可将选定的一个元素
加1或减1。 您可以假设数组的长度最多为10000。

例如:

输入:
[1,2,3]

输出:
2

说明：
只有两个动作是必要的（记得每一步仅可使其中一个元素加1或减1）： 

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]

来源：LeetCode
链接：https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii/
*/
//最后相等的是中位数
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 0, j = nums.size() - 1;
        int res = 0;
        while(i < j)
        {
            res += (nums[j--] - nums[i++]);
        }
        
        return res;
    }
};