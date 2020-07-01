/*
1493. 删掉一个元素以后全为 1 的最长子数组
给你一个二进制数组 nums ，你需要从中删掉一个元素。

请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。

如果不存在这样的子数组，请返回 0 。

 

提示 1：

输入：nums = [1,1,0,1]
输出：3
解释：删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。
示例 2：

输入：nums = [0,1,1,1,0,1,1,0,1]
输出：5
解释：删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1] 。
示例 3：

输入：nums = [1,1,1]
输出：2
解释：你必须要删除一个元素。
示例 4：

输入：nums = [1,1,0,0,1,1,1,0,1]
输出：4
示例 5：

输入：nums = [0,0,0]
输出：0

来源：LeetCode
链接：https://leetcode-cn.com/problems/longest-subarray-of-1s-after-deleting-one-element/
*/
//方法一：滑动窗口
class Solution {
public:
    /*
    滑动窗口
    1.没遇到0，右指针向右走，记录和
    2.第一次遇到0，不管，右指针继续向右走
    3.第二次遇到0，把左指针移到第一个 0 的下一个位置，和要删掉第一个 0 前所有的 1
    4.如果从未遇到0，答案减一
    */
    int longestSubarray(vector<int>& nums) {
        int left = 0, ret = 0, res = 0, sum = 0;
        for(int right = 0; right < nums.size(); ++right)
        {
            if(nums[right] == 1)
            {
                ++sum;
                res = max(sum, res);
            }
            else
            {
                if(ret == 0)
                {
                    ++ret;
                }
                else
                {
                    while(nums[left++] != 0)
                        --sum;
                }
            }
        }
        if(ret == 0)
            --res;
        
        return res;
    }
};

/*
方法二：
1.sum1 存放中间有一个 0 的和
2.sum2 存放中间没有 0 的和
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, sum1 = 0, sum2 = 0, res = 0;
        for(int right = 0; right < nums.size(); ++right)
        {
            if(nums[right] == 1)
            {
                ++sum1;
                ++sum2;
                res = max(res, sum1);
            }
            else
            {
                sum1 = sum2;
                sum2 = 0;
            }
        }
        
        return res == nums.size() ? res - 1 : res;
    }
};

 


  


