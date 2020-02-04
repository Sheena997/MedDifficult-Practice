/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        int left = 0, right = nums.size() - 1;
        vector<int> res;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target)
                right = mid;
            else 
                left = mid + 1;
        }
        
        if(nums[right] != target)
            return {-1, -1};
        else 
            res.push_back(right);
        
        right = nums.size();
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target)
                left = mid + 1;
            else 
                right = mid;
        }
        res.push_back(left - 1);
        
        return res;
    }
};