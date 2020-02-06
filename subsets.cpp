/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
示例:
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        
        for(int i = 0; i < nums.size(); ++i)
        {
            int count = res.size();
            
            for(int j = 0; j < count; ++j)
            {
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                
                res.push_back(tmp);
            }
        }
        
        return res;
    }
};