class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    bool flag=true;
    int top_element;
    MyStack() {
        
    }
    
    void push(int x) {
        if(flag){
            top_element=x;
            q1.push(x);
        }else{
            top_element=x;
            q2.push(x);
        }
    }
    
    int pop() {
        if(flag){
            int size=q1.size();
            for(int i=0;i<size-1;++i){
                if(q1.size()==2){
                    top_element=q1.front();
                }
                q2.push(q1.front());
                q1.pop();
            }
            int a=q1.front();
            q1.pop();
            flag=false;
            return a;
        }else{
            int size=q2.size();
            for(int i=0;i<size-1;++i){
                if(q2.size()==2){
                    top_element=q2.front();
                }
                q1.push(q2.front());
                q2.pop();
            }
            int a=q2.front();
            q2.pop();
            flag=true;
            return a;
        }
    }
    
    int top() {
        return top_element;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */