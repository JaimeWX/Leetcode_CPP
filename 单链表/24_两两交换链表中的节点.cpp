/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {   
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *dummtHead = new ListNode(0);
        ListNode *cur = dummtHead;
        cur->next = head;
        while(cur->next != nullptr)
        {   
            if(cur->next->next != nullptr)
            {
            ListNode *s1 = cur->next;
            ListNode *s2 = cur->next->next;
            ListNode *tmp = s2->next;

            cur->next = s2;
            cur->next->next = s1;
            cur = cur->next->next;
            cur->next = tmp;
            }
            else
                cur = cur->next;
        }
        return dummtHead->next;
    }
};
// @lc code=end

