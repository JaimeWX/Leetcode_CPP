class MinStack {
public:
    stack<int> st;
    stack<int> aux_st;
    MinStack() 
    {
        aux_st.push(INT_MAX);
    }
    
    void push(int val) 
    {
        st.push(val);
        aux_st.push(min(aux_st.top(), val));
    }
    
    void pop() 
    {
        st.pop();
        aux_st.pop();
    }
    
    int top() 
    {
        return st.top();
    }
    
    int getMin() 
    {
        return aux_st.top();
    }   
};
