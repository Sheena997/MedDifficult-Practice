/*
������ 10.02. ��λ����
��дһ�ַ��������ַ�������������򣬽����б�λ�������һ��
��λ����ָ��ĸ��ͬ�������в�ͬ���ַ�����

ע�⣺�������ԭ�������޸�

ʾ��:

����: ["eat", "tea", "tan", "ate", "nat", "bat"],
���:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
˵����

���������ΪСд��ĸ��
�����Ǵ������˳��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/group-anagrams-lcci/
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> unmp;
        vector<vector<string>> res;
        
        for(int i = 0; i < strs.size(); ++i)
        {
            string ret = strs[i];
            sort(ret.begin(), ret.end());
            unmp[ret].push_back(strs[i]);
        }
        
        for(auto e : unmp)
        {
            res.push_back(e.second);
        }
        
        return res;
    }
};