/*
������ 16.06. ��С��
����������������a��b�����������С�����ֵ��һ����ֵ��ÿ��������ȡһ��ֵ����
�����ظö���ֵ�Ĳ�

ʾ����

���룺{1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
����� 3������ֵ��(11, 8)
��ʾ��

1 <= a.length, b.length <= 100000
-2147483648 <= a[i], b[i] <= 2147483647
��ȷ���������[-2147483648, 2147483647]��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/smallest-difference-lcci/
*/
class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long res = INT_MAX;
        int i = 0, j = 0;
        while(i < a.size() && j < b.size())
        {
            res = min(res, abs((long)a[i] - (long)b[j]));
            if(a[i] < b[j])
                ++i;
            else
                ++j;
        }
           
        return res;
    }
};