class MinStack {
public:
stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int value) {
        int mini=INT_MAX;
        if(st.empty()){
             mini= value;
        }
        else{
            mini = min(st.top().second,value);
        }
            st.push({value,mini});
    }
    
    void pop() {
       if(st.size()>1) st.pop();
    }
    
    int top() {
    return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */