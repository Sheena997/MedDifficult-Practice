/*
421. 数组中两个数的最大异或值
给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。

找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。

你能在O(n)的时间解决这个问题吗？

示例:

输入: [3, 10, 5, 25, 2, 8]

输出: 28

解释: 最大的结果是 5 ^ 25 = 28.
通过次数4,653提交次数7,974

来源：LeetCode
链接：https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/
/*
    第一， 2^n > 2^(n-1) + 2^(n-2) + .. 2^0，所以，从高位往低位走，每一位如果可以为1，那么一定是最佳路径
    第二，从一可得，我们一开始从高位开始往下，并且暂时不考虑低位，但是如何快速取每一个数字的指定高位
        mask |= (1 << i);
        nums_mask = mask & nums[j]
        这两步即可取到每一个数字的指定前n位
    第三， a ^ b  = c 那么 a ^ c = b, b ^ c = a
        我们假设这一位的结果为1
        那么如果 nums_mask_one ^ res = nums_mask_two
        那么这个res就满足了，否则跳过
*/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for(int i = 31; i >= 0; --i)
        {
            mask |= (1 << i);
            unordered_set<int> pre_set;
            for(int j = 0; j < nums.size(); ++j)
                pre_set.insert(mask & nums[j]);
            int tmp = res | (1 << i);
            unordered_set<int>::iterator prit = pre_set.begin();
            while(prit != pre_set.end())
            {
                int val = tmp ^ *prit;
                if(pre_set.count(val) != 0)
                {
                    res = tmp;
                    break;
                }
                ++prit;
            }
        }
        
        return res;
    }
};
          
       