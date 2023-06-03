//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int f(int i,int cost,int k,vector<vector<int>>&dp,vector<int>&nums){
        if(i==nums.size())return 0;
        if(dp[i][cost]!=-1)return dp[i][cost];
        if(cost!=0){
            int ans1=INT_MAX;
            if(cost+nums[i]+1<=k){
                 ans1=f(i+1,cost+nums[i]+1,k,dp,nums);
            }
            int ans2=(k-cost)*(k-cost)+f(i,0,k,dp,nums);
            dp[i][cost]=min(ans1,ans2);
        }
        else{
            dp[i][cost]=f(i+1,nums[i],k,dp,nums);
        }
        return dp[i][cost];
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return f(0,0,k,dp,nums);
        
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends