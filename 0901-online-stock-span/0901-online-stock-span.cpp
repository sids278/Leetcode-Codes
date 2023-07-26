class StockSpanner {
public:
    stack<pair<int,int>>st; // create pair of {price , span}
    StockSpanner() {
        
    }
    int next(int price) {
        int span = 1 ;// in starting span of all prices will be 1,which is itself
        //st.top().first= price and st.top().second = span
        while(!st.empty() && st.top().first <=price ){
            span = span + st.top().second;
            st.pop();
        }
        st.push({ price , span});
        return span;
    } 
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */