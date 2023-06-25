class Solution {
public:
    bool same(stack<int>&st,vector<int>&target){
        if(st.size()!=target.size())return false;
        for(int i=st.size()-1;i>=0;i--){
            if(st.top()!=target[i])return false;
            st.pop();
        }
        return true;
    }
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int>st;
        int m=target.size();
        vector<string>ans;
        unordered_map<int,int>map;
        for(int i=0;i<m;i++){
            map[target[i]]=i;
        }
        for(int i=1;i<=n;i++){
            if(same(st,target))return ans;
            if(map.find(i)!=map.end()){
                st.push(i);
                ans.push_back("Push");
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
        
        
    }
};