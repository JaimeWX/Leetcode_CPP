class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {   
        ListNode *pre = NULL;
        ListNode *cur = head;
        return reverse(pre,cur);
    }
    ListNode* reverse(ListNode* pre, ListNode* cur)
    {
        if(cur==nullptr) return pre;
        ListNode *tmp = cur->next;
        cur->next = pre;
        return reverse(cur,tmp);
    }
};