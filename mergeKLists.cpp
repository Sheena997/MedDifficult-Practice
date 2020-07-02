/*
23. 合并K个排序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

来源：LeetCode
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists/
*/
//自己写的暴力的
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


//优先级队列的暴力法
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
分治法：
k个链表两两配对，进行第一轮合并，结束后k个链表被合并成k/2个链表
k/2个链表依然两两配对，进行第二轮合并，结束后k/2个链表被合并成k/4个链表
重复上述过程，进行log(k)次合并，完成总体合并工作
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


