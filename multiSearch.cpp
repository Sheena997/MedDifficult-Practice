/*
面试题 17.17. 多次搜索
给定一个较长字符串big和一个包含较短字符串的数组smalls，
设计一个方法，根据smalls中的每一个较短字符串，对big进
行搜索。输出smalls中的字符串在big里出现的所有位置positions，
其中positions[i]为smalls[i]出现的所有位置。

示例：

输入：
big = "mississippi"
smalls = ["is","ppi","hi","sis","i","ssippi"]
输出： [[1,4],[8],[],[3],[1,4,7,10],[5]]
提示：

0 <= len(big) <= 1000
0 <= len(smalls[i]) <= 1000
smalls的总字符数不会超过 100000。
你可以认为smalls中没有重复字符串。
所有出现的字符均为英文小写字母。

来源：LeetCode
链接：https://leetcode-cn.com/problems/multi-search-lcci/
*/
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> res;
        
        for(auto& str : smalls)
        {
            vector<int> ret;
            if(str != "")
            {
                auto it = big.find(str);
                while(it != string::npos)
                {
                    ret.push_back(it);
                    it = big.find(str, it + 1);//更新迭代器
                }
            }
            
            res.push_back(ret);
        }
        
        return res;
    }
};

