/*
791. �Զ����ַ�������
�ַ���S�� T ֻ����Сд�ַ�����S�У������ַ�ֻ�����һ�Ρ�
S �Ѿ�����ĳ�ֹ����������������Ҫ����S�е��ַ�˳���T��������
�������˵�����S��x��y֮ǰ���֣���ô���ص��ַ�����xҲӦ������y֮ǰ��
��������һ�ַ����������ַ���T��

ʾ��:
����:
S = "cba"
T = "abcd"
���: "cbad"
����: 
S�г������ַ� "a", "b", "c", ���� "a", "b", "c" ��˳��Ӧ���� "c", "b", "a". 
���� "d" û����S�г���, �����Է���T������λ��. "dcba", "cdba", "cbda" ���ǺϷ��������

ע��:
S����󳤶�Ϊ26������û���ظ����ַ���
T����󳤶�Ϊ200��
S��Tֻ����Сд�ַ���

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/custom-sort-string/
*/
class Solution {
public:
    string customSortString(string S, string T) {
        int index = 0;
        
        for(int i = 0; i < S.size(); ++i)
        {
            for(int j = index; j < T.size(); ++j)
            {
                if(S[i] == T[j])
                    swap(T[j], T[index++]);
            }
        }
        
        return T;
    }
};