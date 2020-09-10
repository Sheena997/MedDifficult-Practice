/*
825. ���������
���ǻụ�෢�ͺ����������ڸ���һ��������������������飬ages[i] ��ʾ�� i ���˵����䡣

������������һ����ʱ��A ���ܸ� B��A��B��Ϊͬһ�ˣ����ͺ�������

age[B] <= 0.5 * age[A] + 7
age[B] > age[A]
age[B] > 100 && age[A] < 100
����A ���Ը� B ���ͺ�������

ע����� A �� B ���������󣬲����� B Ҳһ������ A �������󡣶��ң����ǲ�����Լ����ͺ������� 

���ܹ��ᷢ�����ٷݺ�������?

 

ʾ�� 1��

���룺[16,16]
�����2
���ͣ����˿��Ի����������롣
ʾ�� 2��

���룺[16,17,18]
�����2
���ͣ���������ɲ����� 17 -> 16, 18 -> 17.
ʾ�� 3��

���룺[20,30,100,110,120]
�����3
���ͣ���������ɲ����� 110 -> 100, 120 -> 110, 120 -> 100.
 

��ʾ��

1 <= ages.length <= 20000.
1 <= ages[i] <= 120.

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/friends-of-appropriate-ages/
*/
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> unmp;
        for(auto e : ages)
            ++unmp[e];
        
        int res = 0;
        
        for(auto e : unmp)
        {
            for(auto i : unmp)
            {
                if(i.first <= 0.5 * e.first + 7 || i.first > e.first || (i.first > 100 && e.first < 100))
                    continue;
                
                if(e.first == i.first)
                    res += (e.second * (i.second - 1));
                else
                    res += (e.second * i.second);
            }
        }
        
        return res;
    }
};