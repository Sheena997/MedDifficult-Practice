/*
1019. �����е���һ������ڵ�
����һ����ͷ�ڵ� head ��Ϊ��һ���ڵ�����������еĽڵ�ֱ���Ϊ��node_1, node_2, node_3, ... ��
ÿ���ڵ㶼��������һ������ֵ��next larger value�������� node_i������� next_larger(node_i) �� node_j.val��
��ô���� j > i ��  node_j.val > node_i.val���� j �ǿ��ܵ�ѡ������С���Ǹ������������������ j����ô��һ������ֵΪ 0 ��
�������������� answer������ answer[i] = next_larger(node_{i+1}) ��
ע�⣺�������ʾ���У����� [2,1,5] ���������루�������������������л���ʾ����ͷ�ڵ��ֵΪ 2���ڶ����ڵ�ֵΪ 1��
�������ڵ�ֵΪ 5 �� 

ʾ�� 1��
���룺[2,1,5]
�����[5,5,0]

ʾ�� 2��
���룺[2,7,4,3,5]
�����[7,0,5,5,0]

ʾ�� 3��
���룺[1,7,5,1,9,2,5,1]
�����[7,9,9,9,0,5,0,0]
 

��ʾ��
���������е�ÿ���ڵ㣬1 <= node.val <= 10^9
�����б�ĳ����� [0, 10000] ��Χ��

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/next-greater-node-in-linked-list/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        if(head == nullptr || head->next == nullptr)
            return {0};
        ListNode* cur = head->next;
        
        while(head && cur)
        {
            int ret = head->val;
            while(cur)
            {
                if(ret < cur->val)
                {
                    ret = cur->val;
                    break;
                }
                cur = cur->next;
            }
            if(ret == head->val)
                ret = 0;
            res.push_back(ret);
            head = head->next;
            cur = head->next;
        }
        res.push_back(0);
        return res;
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> memst;
        int i = 0;
        
        while(head)
        {
            while(!memst.empty() && head->val > res[memst.top()])
            {
                res[memst.top()] = head->val;
                memst.pop();
            }
            
            res.push_back(head->val);
            memst.push(i++);
            head = head->next;
        }
        
        while(!memst.empty())
        {
            res[memst.top()] = 0;
            memst.pop();
        }
        
        return res;
    }
};