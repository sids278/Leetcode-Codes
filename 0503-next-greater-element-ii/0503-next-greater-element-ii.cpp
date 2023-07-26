class Solution {
public:
    // [1,2,3,4,3]
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<nums[i]){
                ans[s.top()]=nums[i];
                s.pop();
            }
            s.push(i);
        }
        stack<int>st;
        for(int i=0;i<n;i++){
            if(ans[i]==-1)st.push(i);
        }
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                ans[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};