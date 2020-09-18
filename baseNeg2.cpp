/*
1017. ��������ת��
�������� N������������ "0" �� "1"��ɵ��ַ��������ַ���Ϊ N �ĸ������ƣ�base -2����ʾ��
�����ַ������� "0"�����򷵻ص��ַ����в��ܺ���ǰ���㡣

ʾ�� 1��
���룺2
�����"110"
���ͣ�(-2) ^ 2 + (-2) ^ 1 = 2

ʾ�� 2��
���룺3
�����"111"
���ͣ�(-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3

ʾ�� 3��
���룺4
�����"100"
���ͣ�(-2) ^ 2 = 4
 
��ʾ��
0 <= N <= 10^9

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/convert-to-base-2/
*/
class Solution {
public:
    string baseNeg2(int N) {
        if(N == 0)
            return "0";
        
        string res;
        
        while(N)
        {
            int tmp = abs(N % (-2));
            N = (N - tmp) / (-2);
            
            res += to_string(tmp);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};