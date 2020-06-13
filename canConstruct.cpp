/*
1400. 构造 K 个回文字符串
给你一个字符串 s 和一个整数 k 。请你用 s 字符串中 所有字符 构造 k 个非空 回文串 。
如果你可以用 s 中所有字符构造 k 个回文字符串，那么请你返回 True ，否则返回 False 。

示例 1：

输入：s = "annabelle", k = 2
输出：true
解释：可以用 s 中所有字符构造 2 个回文字符串。
一些可行的构造方案包括："anna" + "elble"，"anbna" + "elle"，"anellena" + "b"
示例 2：

输入：s = "leetcode", k = 3
输出：false
解释：无法用 s 中所有字符构造 3 个回文串。
示例 3：

输入：s = "true", k = 4
输出：true
解释：唯一可行的方案是让 s 中每个字符单独构成一个字符串。
示例 4：

输入：s = "yzyzyzyzyzyzyzy", k = 2
输出：true
解释：你只需要将所有的 z 放在一个字符串中，所有的 y 放在另一个字符串中。
那么两个字符串都是回文串。
示例 5：

输入：s = "cr", k = 7
输出：false
解释：我们没有足够的字符去构造 7 个回文串。

来源：LeetCode
链接：https://leetcode-cn.com/problems/construct-k-palindrome-strings/
*/
class Solution {
public:
    bool canConstruct(string s, int k) {
        /*
        如果为奇数字符的个数超过 k 个，那么直接返回 false，否则返回 true
		原理：如果最多只存在 k 个奇数字符，那么将这 k 个奇数字符平均分配给
        k 个回文串，一个回文串一个，然后将偶数字符随机分配即可,但如果超过 k 
        个，那么怎么也构不成 k 个回文串
        */
        if(k > s.size())
            return false;
        vector<int> vc(26, 0);
        for(auto& e : s)
            ++vc[e - 'a'];
        
        int count = 0;
        for(auto e : vc)
        {
            if(e != 0)
            {
                if(e % 2 != 0)
                    ++count;
            }
        }
        
       return count <= k;    
    }
};
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size())
            return false;
        vector<int> vc(26, 0);
        int count = 0;
        /*回文串在于中心元素，最少的就是那些无法被配对的哪些孤单的字符,
        最多就是每个都可以当一个回文串*/
        for(auto& e : s)
            ++vc[e - 'a'];
        for(auto i : vc)
            count += i&1; // i&1=0表示i是偶数，i&1 = 1表示i是奇数
        
        return count <= k;
    }
};