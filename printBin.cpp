/*
������ 05.02. ��������ת�ַ���
��������ת�ַ���������һ������0��1֮���ʵ������0.72����
����Ϊdouble����ӡ���Ķ����Ʊ��ʽ����������ֲ���0��1
֮�䣬�����޷���ȷ����32λ���ڵĶ����Ʊ�ʾ�����ӡ��ERROR����
ʾ��1:
 ���룺0.625
 �����"0.101"
ʾ��2:
 ���룺0.1
 �����"ERROR"
 ��ʾ��0.1�޷���������׼ȷ��ʾ
��ʾ��

32λ��������е�"0."����λ��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/bianry-number-to-string-lcci/
*/
class Solution {
public:
    string printBin(double num) {
        if(num <= 0 || num >= 1)
            return "ERROR";
        double ret = 0.5;
        string res = "0.";
        
        while(num > 0 && res.size() < 32)
        {
            if(num >= ret)
            {
                num -= ret;
                res.push_back('1');
            }
            else 
            {
                res.push_back('0');
            }
            
            ret /= 2;
        }
        
        return (num == 0) ? res : "ERROR";
    }
};