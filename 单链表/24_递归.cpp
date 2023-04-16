ListNode* swapPairs(ListNode* head)
{
    ListNode *newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}