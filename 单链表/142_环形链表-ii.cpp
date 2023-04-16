class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                ListNode *index1 = fast;
                ListNode *index2 = head;
                while(index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }
};
// @lc code=endnu

