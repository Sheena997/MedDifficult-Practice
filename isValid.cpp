/*
1003. ����滻��Ĵ��Ƿ���Ч
������Ч�ַ��� "abc"��
�����κ���Ч���ַ��� V�����ǿ��Խ� V �ֳ��������� X �� Y��ʹ�� X + Y��X �� Y ���ӣ����� V��
��X �� Y ����Ϊ�ա�����ô��X + "abc" + Y Ҳͬ������Ч�ġ�
���磬��� S = "abc"������Ч�ַ�����ʾ���ǣ�"abc"��"aabcbc"��"abcabc"��"abcabcababcc"��
��Ч�ַ�����ʾ���ǣ�"abccba"��"ab"��"cababc"��"bac"��
��������ַ��� S ��Ч���򷵻� true�����򣬷��� false��
ʾ�� 1��
���룺"aabcbc"
�����true
���ͣ�
����Ч�ַ��� "abc" ��ʼ��
Ȼ�����ǿ����� "a" �� "bc" ֮�������һ�� "abc"������ "a" + "abc" + "bc"���� "aabcbc"��
ʾ�� 2��
���룺"abcabcababcc"
�����true
���ͣ�
"abcabcabc" ����Ч�ģ�������������ԭ������������ "abc"��
Ȼ�����ǿ��������һ����ĸ֮ǰ���� "abc"������ "abcabcab" + "abc" + "c"���� "abcabcababcc"��
ʾ�� 3��
���룺"abccba"
�����false
ʾ�� 4��
���룺"cababc"
�����false
��ʾ��
1 <= S.length <= 20000
S[i] Ϊ 'a'��'b'���� 'c'

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/check-if-word-is-valid-after-substitutions/
*/
class Solution {
public:
    bool isValid(string S) {
        stack<char> st;
        for(auto& e : S)
        {
            if(e == 'a' )
                st.push(e);
            else if(e == 'b')
                st.push(e);
            else if(e == 'c')
            {
                if(st.empty())
                    return false;
                else
                {
                    char a = st.top();
                    st.pop();
                    if(a != 'b' || st.empty())
                        return false;
                    else
                    {
                        char b = st.top();
                        st.pop();
                        if(b != 'a')
                            return false;
                    }
                }
            }
        }
        
        return st.empty();
    }
};
//����
class Solution {
public:
    bool isValid(string S) {
        stack<char> st;
        for(auto& e : S)
        {
            if(st.empty() || e != 'c')
            {
                st.push(e);
            }
            else
            {
                char top = st.top();
                st.pop();
                if(!st.empty() && (top == 'b' && st.top() == 'a'))
                    st.pop();
                else
                    st.push(top);
            }
        }
        
        return st.empty();
    }
};
//�ȽϺ�ʱ�Ľⷨ
class Solution {
public:
    bool isValid(string S) {
        while("" != S)
        {
            if(string::npos == S.find("abc"))
                return false;
            S = S.erase(S.find("abc"), 3);
        }
        
        return true;
    }
};