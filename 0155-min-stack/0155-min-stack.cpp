class MinStack {
public:
    stack<int> s;
    stack<int> ms;
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        if(!ms.empty()){
            ms.push(min(value,ms.top()));
        }else{
            ms.push(value);
        }
    }
    
    void pop() {
        ms.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
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