/*
1400. ���� K �������ַ���
����һ���ַ��� s ��һ������ k �������� s �ַ����� �����ַ� ���� k ���ǿ� ���Ĵ� ��
���������� s �������ַ����� k �������ַ�������ô���㷵�� True �����򷵻� False ��

ʾ�� 1��

���룺s = "annabelle", k = 2
�����true
���ͣ������� s �������ַ����� 2 �������ַ�����
һЩ���еĹ��췽��������"anna" + "elble"��"anbna" + "elle"��"anellena" + "b"
ʾ�� 2��

���룺s = "leetcode", k = 3
�����false
���ͣ��޷��� s �������ַ����� 3 �����Ĵ���
ʾ�� 3��

���룺s = "true", k = 4
�����true
���ͣ�Ψһ���еķ������� s ��ÿ���ַ���������һ���ַ�����
ʾ�� 4��

���룺s = "yzyzyzyzyzyzyzy", k = 2
�����true
���ͣ���ֻ��Ҫ�����е� z ����һ���ַ����У����е� y ������һ���ַ����С�
��ô�����ַ������ǻ��Ĵ���
ʾ�� 5��

���룺s = "cr", k = 7
�����false
���ͣ�����û���㹻���ַ�ȥ���� 7 �����Ĵ���

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/construct-k-palindrome-strings/
*/
class Solution {
public:
    bool canConstruct(string s, int k) {
        /*
        ���Ϊ�����ַ��ĸ������� k ������ôֱ�ӷ��� false�����򷵻� true
		ԭ��������ֻ���� k �������ַ�����ô���� k �������ַ�ƽ�������
        k �����Ĵ���һ�����Ĵ�һ����Ȼ��ż���ַ�������伴��,��������� k 
        ������ô��ôҲ������ k �����Ĵ�
        */
        if(k > s.size())
            return false;
        vector<int> vc(26, 0);
        for(auto& e : s)
            ++vc[e - 'a'];
        
        int count = 0;
        for(auto e : vc)
        {
            if(e != 0)
            {
                if(e % 2 != 0)
                    ++count;
            }
        }
        
       return count <= k;    
    }
};
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size())
            return false;
        vector<int> vc(26, 0);
        int count = 0;
        /*���Ĵ���������Ԫ�أ����ٵľ�����Щ�޷�����Ե���Щ�µ����ַ�,
        ������ÿ�������Ե�һ�����Ĵ�*/
        for(auto& e : s)
            ++vc[e - 'a'];
        for(auto i : vc)
            count += i&1; // i&1=0��ʾi��ż����i&1 = 1��ʾi������
        
        return count <= k;
    }
};