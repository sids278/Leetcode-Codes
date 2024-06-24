class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>ans;
        unordered_map<int,int>mp;
        int n=nums.size();
        vector<int>ans2;
        if(n<=k)return nums;
        for(auto x:nums){
            mp[x]++;
        }
        for(auto x:mp){
            ans.push_back({x.second,x.first});
        }
        sort(ans.begin(),ans.end(),greater<pair<int,int>>());
        for(int i=0;i<k;i++){
            ans2.push_back(ans[i].second);
        }
        return ans2;
    }
};