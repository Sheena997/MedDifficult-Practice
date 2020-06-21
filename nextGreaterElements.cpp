/*
503. 下一个更大元素 II
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），
输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组
遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地
搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:

输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
注意: 输入数组的长度不会超过 10000。

来源：LeetCode
链接：https://leetcode-cn.com/problems/next-greater-element-ii/
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> st;
        for(int i = nums.size() - 2; i >= 0; --i)
            st.push(nums[i]);
        
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            while(!st.empty() && nums[i] >= st.top())
                st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        
        return res;
    }
};

//单调栈
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> st;
        
        //数组长度翻倍
        for(int  i = 2 * nums.size() - 1; i >=0 ;--i)
        {
            while(!st.empty() && st.top() <= nums[i % nums.size()])
                st.pop();
            res[i % nums.size()] = st.empty() ? -1 : st.top();
            st.push(nums[i % nums.size()]);
        }
        
        return res;
    }
};