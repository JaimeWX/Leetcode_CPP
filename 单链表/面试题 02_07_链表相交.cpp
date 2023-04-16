struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include<math.h>

class Solution 
{
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
        {
            int headA_length = getLinkedListLength(headA);
            int headB_length = getLinkedListLength(headB);

            int length_difference = abs(headA_length-headB_length);

            if(length_difference != 0)
            {
                while(length_difference--)
                {
                    if(headA_length > headB_length)
                        headA = headA->next;
                    else
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

        int getLinkedListLength(ListNode *head)
        {
            int length = 0;
            while(head != nullptr)
            {
                length++;
                head = head->next;
            }
            return length;
        }
};