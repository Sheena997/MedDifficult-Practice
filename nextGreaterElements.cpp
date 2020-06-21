/*
503. ��һ������Ԫ�� II
����һ��ѭ�����飨���һ��Ԫ�ص���һ��Ԫ��������ĵ�һ��Ԫ�أ���
���ÿ��Ԫ�ص���һ������Ԫ�ء����� x ����һ�������Ԫ���ǰ�����
����˳���������֮��ĵ�һ�������������������ζ����Ӧ��ѭ����
����������һ�������������������ڣ������ -1��

ʾ�� 1:

����: [1,2,1]
���: [2,-1,2]
����: ��һ�� 1 ����һ����������� 2��
���� 2 �Ҳ�����һ����������� 
�ڶ��� 1 ����һ����������Ҫѭ�����������Ҳ�� 2��
ע��: ��������ĳ��Ȳ��ᳬ�� 10000��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/next-greater-element-ii/
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> st;
        for(int i = nums.size() - 2; i >= 0; --i)
            st.push(nums[i]);
        
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            while(!st.empty() && nums[i] >= st.top())
                st.pop();
            res[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        
        return res;
    }
};

//����ջ
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> st;
        
        //���鳤�ȷ���
        for(int  i = 2 * nums.size() - 1; i >=0 ;--i)
        {
            while(!st.empty() && st.top() <= nums[i % nums.size()])
                st.pop();
            res[i % nums.size()] = st.empty() ? -1 : st.top();
            st.push(nums[i % nums.size()]);
        }
        
        return res;
    }
};