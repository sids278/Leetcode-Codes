class Solution {
public:
    int func(int i, int prev, int n, vector<int>& arr1, vector<int>& arr2, map<pair<int,int>,int>& dp){
        if(i == n){
            return 0;
        }
        if(dp.find({i,prev})!=dp.end()){
            return dp[{i,prev}];
        }
        int ind = upper_bound(arr2.begin(),arr2.end(),prev) - arr2.begin();
        int ans = 2001; //There can be at max 2000 operations
        if(arr1[i]>prev){
            ans = min(ans,func(i+1,arr1[i],n,arr1,arr2,dp));
        }
        if(ind<arr2.size()){
            ans = min(ans,func(i+1,arr2[ind],n,arr1,arr2,dp)+1);
        }
        return dp[{i,prev}] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int n = arr1.size();
        map<pair<int,int>, int> dp;
        int ans = func(0,-1,n,arr1,arr2,dp);
        if(ans>=2001){
            return -1;
        }
        return ans;
    }
};