/*
��ָ Offer 45. �������ų���С����
����һ���Ǹ��������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����

ʾ�� 1:

����: [10,2]
���: "102"
ʾ�� 2:

����: [3,30,34,5,9]
���: "3033459"
 

��ʾ:

0 < nums.length <= 100
˵��:

���������ܷǳ�����������Ҫ����һ���ַ�������������
ƴ�����������ֿ��ܻ���ǰ�� 0�����������Ҫȥ��ǰ�� 0

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
*/
//static����
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

//lamberda���ʽ
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

//�º���
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