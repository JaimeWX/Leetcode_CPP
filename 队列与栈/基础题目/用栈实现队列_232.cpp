class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() 
    {

    }

    void push(int x) 
    {
        s1.push(x);
    }
    
    int pop() 
    {
        if(s2.empty() && !s1.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int top_element = s2.top();
            s2.pop();
            return top_element;
        }
        else
        {
            int top_element = s2.top();
            s2.pop();
            return top_element;
        }
    }
    
    int peek() 
    {
        if(s2.empty() && !s1.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
        else    
            return s2.top();
    }
    
    bool empty() 
    {
        if(s1.empty() && s2.empty())    return true;
        else    return false;
    }
};
