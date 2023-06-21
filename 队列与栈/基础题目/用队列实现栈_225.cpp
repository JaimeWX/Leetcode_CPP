class MyStack {
public:
    queue<int> que;
    queue<int> aux_que;
    MyStack() 
    {

    }
    
    void push(int x) 
    {
        que.push(x);
    }
    
    int pop() 
    {
        int size = que.size();
        size--;
        while(size--)
        {
            aux_que.push(que.front());
            que.pop();
        }
        int top_element = que.front();
        que.pop();
        que = aux_que;
        while(!aux_que.empty())
        {
            aux_que.pop();
        }
        return top_element;
    }
    
    int top() 
    {
        return que.back();
    }
    
    bool empty() 
    {
        if(que.empty())  return true;
        else    return false;
    }
};