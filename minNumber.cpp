/*
剑指 Offer 45. 把数组排成最小的数
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

示例 1:

输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"
 

提示:

0 < nums.length <= 100
说明:

输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

来源：LeetCode
链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
*/
//static函数
class Solution {
public:
    static bool cmpare(const string& a, const string& b)
    {
        return a + b < b + a;
    }
    string minNumber(vector<int>& nums) {
        vector<string> vs;
        string res;
        for(auto num : nums)
            vs.push_back(to_string(num));
        
        sort(vs.begin(), vs.end(), cmpare);
        
        for(auto e : vs)
            res += e;
        
        return res;
    }
};

//lamberda表达式
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> vs;
        string res;
        for(auto num : nums)
            vs.push_back(to_string(num));
        
        sort(vs.begin(), vs.end(), [](const string& a, const string& b) 
             {
                 return a + b < b + a;
             });
        
        for(auto e : vs)
            res += e;
        
        return res;
    }
};

//仿函数
class cmp
{
public:
    bool operator()(const string& a, const string& b)
    {
        return a + b < b + a;
    }
};
class Solution {
public:
    
    string minNumber(vector<int>& nums) {
        vector<string> vs;
        string res;
        for(auto num : nums)
            vs.push_back(to_string(num));
        
        sort(vs.begin(), vs.end(), cmp());
        
        for(auto e : vs)
            res += e;
        
        return res;
    }
};