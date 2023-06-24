class CustomStack {
public:
    int cap;
    stack<int> st;
    
    CustomStack(int maxSize) {
        cap = maxSize;
    }
    
    void push(int x) {
        if (st.size() < cap) {
            st.push(x);
        }
    }
    
    int pop() {
        if (!st.empty()) {
            int t = st.top();
            st.pop();
            return t;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if(st.empty())return ;
        if(st.size()<=k){
            int t=st.top();
            st.pop();
            increment(k,val);
            st.push(t+val);
        }
        else{
            int t=st.top();
            st.pop();
            increment(k,val);
            st.push(t);
        }
    }
};



/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */