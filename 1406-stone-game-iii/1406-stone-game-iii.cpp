class Solution {
public:
//     int playGame(vector<int>& stones, bool alice, bool bob, int i) {
        
//         if (i >= stones.size()) return 0;
        
//         int ans;
//         int sum = 0;
        
//         if (dp[i][alice][bob] != -1) return dp[i][alice][bob];
        
//         if (alice) {
//             ans = INT_MIN;
//             for (int idx=i; idx < i + 3 && idx < stones.size(); idx++) {
//                 sum += stones[idx];
//                 ans = max(ans, sum + playGame(stones, false, true, idx + 1));
//             }
//         }
        
//         if (bob) {
//             ans = INT_MAX;
//             for (int idx=i; idx < i + 3 && idx < stones.size(); idx++) {
//                 sum += stones[idx];
//                 ans = min(ans, playGame(stones, true, false, idx + 1));
//             }
//         }
        
//         return dp[i][alice][bob] = ans;
//     }
    
    int f(int i,bool alice,vector<int>&v,vector<vector<int>>&dp){
        if(i>=v.size())return 0;
        
        if(dp[i][alice]!=-1)return dp[i][alice];
        int ans;
        int sum=0;
        
        if(alice){
            ans=INT_MIN;
            for (int idx=i; idx < i + 3 && idx < v.size(); idx++){
                sum+=v[idx];
                ans=max(ans,sum+f(idx+1,!alice,v,dp));
            }
            
        }
        else{
            ans=INT_MAX;
            
            for (int idx=i; idx < i + 3 && idx < v.size(); idx++){
                sum+=v[idx];
                ans=min(ans,f(idx+1,!alice,v,dp));
            }
        }
    
        return dp[i][alice]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int x=f(0,true,stoneValue,dp);
        int total=0;
        for(auto y:stoneValue){
            total+=y;
        }
        
        if(total-x<x)return "Alice";
        if(total-x>x)return "Bob";
        return "Tie";
        
    }
};