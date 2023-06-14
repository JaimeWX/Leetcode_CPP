class MyLinkedList {
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x): val(x), next(nullptr){}
    };

    ListNode* _dummyHead;
    int _size;
public:
    MyLinkedList() 
    {
        _dummyHead = new ListNode(0);
        _size = 0;
    }
    
    int get(int index) 
    {
        if(index < 0 || index > (_size-1))   return -1;
        ListNode* cur = _dummyHead->next;
        while(index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) 
    {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) 
    {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index > _size)   return ;
        if(index < 0)   index = 0;
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while(index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) 
    {
        if(index < 0 || index > (_size-1))  return ;
        ListNode* cur = _dummyHead;
        while(index--)
        {
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
};