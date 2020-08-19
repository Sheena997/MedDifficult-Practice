/*
面试题 17.06. 2出现的次数
编写一个方法，计算从 0 到 n (含 n) 中数字 2 出现的次数。

示例:
输入: 25
输出: 9
解释: (2, 12, 20, 21, 22, 23, 24, 25)(注意 22 应该算作两次)
提示：
n <= 10^9

来源：LeetCode
链接：https://leetcode-cn.com/problems/number-of-2s-in-range-lcci/
*/
class Solution {
public:
    int numberOf2sInRange(int n) {
        int res = 0;
        long i = 1;
        while(n / i != 0)
        {
            int high = n / (10 * i);
            int cur = (n / i) % 10;
            int low = n - (n / i) * i;
            
            if(cur < 2)
                res += high * i;
            else if(cur == 2)
                res += high * i + low + 1;
            else
                res += (high + 1) * i;
            i *= 10;
        }
        
        return res;
    }
};