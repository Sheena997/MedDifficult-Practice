/*
������ 17.06. 2���ֵĴ���
��дһ������������� 0 �� n (�� n) ������ 2 ���ֵĴ�����

ʾ��:
����: 25
���: 9
����: (2, 12, 20, 21, 22, 23, 24, 25)(ע�� 22 Ӧ����������)
��ʾ��
n <= 10^9

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/number-of-2s-in-range-lcci/
*/
class Solution {
public:
    int numberOf2sInRange(int n) {
        int res = 0;
        long i = 1;
        while(n / i != 0)
        {
            int high = n / (10 * i);
            int cur = (n / i) % 10;
            int low = n - (n / i) * i;
            
            if(cur < 2)
                res += high * i;
            else if(cur == 2)
                res += high * i + low + 1;
            else
                res += (high + 1) * i;
            i *= 10;
        }
        
        return res;
    }
};