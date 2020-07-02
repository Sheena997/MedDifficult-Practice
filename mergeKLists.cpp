/*
23. �ϲ�K����������
�ϲ� k �������������غϲ������������������������㷨�ĸ��Ӷȡ�

ʾ��:

����:
[
  1->4->5,
  1->3->4,
  2->6
]
���: 1->1->2->3->4->4->5->6

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/merge-k-sorted-lists/
*/
//�Լ�д�ı�����
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> ms;
        for(int i = 0; i < lists.size(); ++i)
        {
            ListNode* head = lists[i];
            while(head)
            {
                ms.insert(head->val);
                head = head->next;
            }
        }
        
        ListNode* tail = new ListNode(0);
        ListNode* head = tail;
        auto sp = ms.begin();
        while(sp != ms.end())
        {
            tail->next = new ListNode(*sp);
            ++sp;
            tail = tail->next;
        }
        return head->next;
    }
};


//���ȼ����еı�����
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* const &a, ListNode* const &b)
        {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for(auto& e : lists)
            if(e != nullptr)
                pq.push(e);
        
        ListNode* tail = new ListNode(0);
        ListNode* head = tail;
        while(!pq.empty())
        {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if(tail->next != nullptr)
                pq.push(tail->next);
        }
        
        return head->next;
    }
};



/*
���η���
k������������ԣ����е�һ�ֺϲ���������k�������ϲ���k/2������
k/2��������Ȼ������ԣ����еڶ��ֺϲ���������k/2�������ϲ���k/4������
�ظ��������̣�����log(k)�κϲ����������ϲ�����
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
    ListNode* _merge(ListNode* l1, ListNode* l2)
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val <= l2->val)
        {
            l1->next = _merge(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = _merge(l1, l2->next);
            return l2;
        }
    }
    ListNode* merge(vector<ListNode*>& lists, int begin, int end)
    {
        if(begin == end)
            return lists[begin];
        int mid = begin + (end - begin)/2;
        ListNode* l1 = merge(lists, begin, mid);
        ListNode* l2 = merge(lists, mid + 1, end);
        
        return _merge(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        
        return merge(lists, 0, lists.size() - 1);
    }
};


