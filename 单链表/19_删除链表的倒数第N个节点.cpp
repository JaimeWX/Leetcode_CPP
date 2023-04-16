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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *cur = head;
        int linkedList_length=0;
        while(cur != nullptr)
        {
            linkedList_length++;
            cur = cur->next;
        }
        
        ListNode *dummyHead = new ListNode(0,head);
        cur = dummyHead;
        int pre_delete = linkedList_length + 1 - n;
         while(pre_delete--)
        {   
            if(pre_delete==0)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};