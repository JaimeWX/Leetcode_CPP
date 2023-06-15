struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp1;
            cur->next->next->next = tmp2;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};

