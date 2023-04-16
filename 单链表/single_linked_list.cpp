#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

/*base_function*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createLinkedList(vector<int> nums)
{   
    ListNode *head = new ListNode();
    ListNode *r = head; 
    for(int i=0; i<nums.size(); i++)
    {
        ListNode *node = new ListNode(nums[i]);
        r->next = node;
        r = node;
    }
    r->next = nullptr;
    return head->next;
}

void listTraverse(ListNode *head)
{   
    while(head != nullptr)
    {
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
}
/*base_function*/

int main()
{
    vector<int>nums = {1,2,3,4,5};
    ListNode *head = createLinkedList(nums);
    listTraverse(head);
    return 0;
}