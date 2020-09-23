/*
������ 17.05.  ��ĸ������
����һ�������ַ������ֵ����飬�ҵ���������飬�Ұ������ַ������ֵĸ�����ͬ��
���ظ������飬�����ڶ��������飬������˵���С�ġ������������������飬����һ�������顣

ʾ�� 1:
����: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]
���: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]

ʾ�� 2:
����: ["A","A"]
���: []

��ʾ��
array.length <= 100000

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/find-longest-subarray-lcci/
*/
class Solution {
public:
    bool isTheAlpha(string& ret)
    {
        if((ret[0] >= 'a' && ret[0] <= 'z') || (ret[0] >= 'A' && ret[0] <= 'Z'))
            return true;
        return false;
    }
    vector<string> findLongestSubarray(vector<string>& array) {
        vector<string> res;
        unordered_map<int, int> unmp;
        unmp[0] = -1;
        int begin = 0, end = 0, sum = 0;
        
        for(int i = 0; i < array.size(); ++i)
        {
            if(isTheAlpha(array[i]))
                ++sum;
            else
                --sum;
            if(unmp.find(sum) != unmp.end())
            {
                if(i - unmp[sum] > end - begin)
                {
                    begin = unmp[sum] + 1;
                    end = i + 1;
                }
            }
            else
            {
                if(unmp.find(sum) == unmp.end())
                    unmp[sum] = i;
            }
        }
        
        for(int i = begin; i < end; ++i)
            res.push_back(array[i]);
        
        return res;
    }
};