#include<math.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int getListLen(ListNode* head)
    {
        int size = 0;
        while(head != nullptr)
        {
            size++;
            head = head->next;
        }
        return size;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int sizeA = getListLen(headA);
        int sizeB = getListLen(headB);
        int sizeDiff = abs(sizeA-sizeB);

        while(sizeDiff--)
        {
            if(sizeA > sizeB)
            {
                headA = headA->next;
            }
            else
            {
                headB = headB->next;
            }
        }

        while(headA != nullptr)
        {
            if(headA == headB)
                return headA;
            else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return headA;
    }
};