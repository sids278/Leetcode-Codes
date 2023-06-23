class MinStack {
private:
    stack<int> s;
    int min = INT_MAX;
    
public:    
    MinStack() {        
    }
    
    void push(int val) {
        if(val <= min){
            s.push(min);    
            min = val;
        }        
        s.push(val);
    }
    
    void pop() {        
        if(s.top() == min) {
            s.pop();
            min = s.top();            
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */