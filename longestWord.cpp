/*
������ 17.15. �����
����һ�鵥��words����дһ�������ҳ����е�����ʣ��Ҹõ�������
�鵥���е�����������϶��ɡ����ж��������ͬ�Ľ�������������ֵ���
��С��һ���û�з���Ҫ��ĵ����򷵻ؿ��ַ�����

ʾ����

���룺 ["cat","banana","dog","nana","walk","walker","dogwalker"]
����� "dogwalker"
���ͣ� "dogwalker"����"dog"��"walker"��ɡ�
��ʾ��

0 <= len(words) <= 200
1 <= len(words[i]) <= 100

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/longest-word-lcci/
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
//�Լ�д�ģ��ݹ�̫��
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