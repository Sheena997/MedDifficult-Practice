/*
������ 17.17. �������
����һ���ϳ��ַ���big��һ�������϶��ַ���������smalls��
���һ������������smalls�е�ÿһ���϶��ַ�������big��
�����������smalls�е��ַ�����big����ֵ�����λ��positions��
����positions[i]Ϊsmalls[i]���ֵ�����λ�á�

ʾ����

���룺
big = "mississippi"
smalls = ["is","ppi","hi","sis","i","ssippi"]
����� [[1,4],[8],[],[3],[1,4,7,10],[5]]
��ʾ��

0 <= len(big) <= 1000
0 <= len(smalls[i]) <= 1000
smalls�����ַ������ᳬ�� 100000��
�������Ϊsmalls��û���ظ��ַ�����
���г��ֵ��ַ���ΪӢ��Сд��ĸ��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/multi-search-lcci/
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
                    it = big.find(str, it + 1);//���µ�����
                }
            }
            
            res.push_back(ret);
        }
        
        return res;
    }
};

