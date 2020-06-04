/*
面试题 05.02. 二进制数转字符串
二进制数转字符串。给定一个介于0和1之间的实数（如0.72），
类型为double，打印它的二进制表达式。如果该数字不在0和1
之间，或者无法精确地用32位以内的二进制表示，则打印“ERROR”。
示例1:
 输入：0.625
 输出："0.101"
示例2:
 输入：0.1
 输出："ERROR"
 提示：0.1无法被二进制准确表示
提示：

32位包括输出中的"0."这两位。

来源：LeetCode
链接：https://leetcode-cn.com/problems/bianry-number-to-string-lcci/
*/
class Solution {
public:
    string printBin(double num) {
        if(num <= 0 || num >= 1)
            return "ERROR";
        double ret = 0.5;
        string res = "0.";
        
        while(num > 0 && res.size() < 32)
        {
            if(num >= ret)
            {
                num -= ret;
                res.push_back('1');
            }
            else 
            {
                res.push_back('0');
            }
            
            ret /= 2;
        }
        
        return (num == 0) ? res : "ERROR";
    }
};