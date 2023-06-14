struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* pre = nullptr;
        ListNode* cur = head;

        ListNode* tmp;
        while(cur != nullptr)
        {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }
};