struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        int size = 0;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr)
        {
            size++;
            cur = cur->next;
        }
        cur = dummyHead;
        int loop = size-n;
        while(loop--)
        {
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        return dummyHead->next;
    }
};