class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(auto x:s){
            if(x=='(')st.push(x);
            else if(x==')'){
                if(st.size() && st.top()=='(')st.pop();
                else st.push(x);
            }
        }
        return st.size();
    }
};