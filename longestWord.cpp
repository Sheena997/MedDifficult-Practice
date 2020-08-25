/*
面试题 17.15. 最长单词
给定一组单词words，编写一个程序，找出其中的最长单词，且该单词由这
组单词中的其他单词组合而成。若有多个长度相同的结果，返回其中字典序
最小的一项，若没有符合要求的单词则返回空字符串。

示例：

输入： ["cat","banana","dog","nana","walk","walker","dogwalker"]
输出： "dogwalker"
解释： "dogwalker"可由"dog"和"walker"组成。
提示：

0 <= len(words) <= 200
1 <= len(words[i]) <= 100

来源：LeetCode
链接：https://leetcode-cn.com/problems/longest-word-lcci/
*/
class Solution {
public:
    bool isValid(string s, unordered_set<string>& record, int cnt)
    {
        if(s.empty() && cnt > 1)
            return true;
        
        for(int i = 1; i <= s.size(); ++i)
        {
            if(record.count(s.substr(0, i)) && isValid(s.substr(i), record, cnt + 1))
                return true;
        }
        return false;
    }   
    string longestWord(vector<string>& words) {
        if(words.empty())
            return "";
        string res = "";
        
        int maxLen = 0;
        unordered_set<string> record(words.begin(), words.end());
        for(auto i : words)
        {
            if(isValid(i, record, 0))
            {
                if(i.size() > maxLen)
                {
                    res = i;
                    maxLen = res.size();
                }
                else if(i.size() == maxLen)
                {
                    if(i < res)
                        res = i;
                }
            }
        }
        
        return res;
    }
};

/*
//自己写的，递归太深
class Solution {
public:
    void dfs(vector<string>& words, string& res, int cur, int index,  string& ret)
    {
	    if (cur == words.size())
		    return;
	    int j = 0;
	    for (j  = 0; j < words.size(); ++j)
	    {
		    if (j != index && ret == words[j])
		    {
			    if (ret.size() > res.size())
				    res = ret;
		    }
	    }
	
    	for (int i = 0; i < words.size(); ++i)
	    {
		    string tmp = ret;
		    ret += words[i];
		    dfs(words, res, cur + 1, i, ret);
		    if (i == words.size() - 1)
	    		return;
		    ret = tmp;
	    }
    }
    string longestWord(vector<string>& words) {
	    string res = "";
	    string ret = "";
	    dfs(words, res, 0, 0, ret);

	    return res;
    }
};
*/