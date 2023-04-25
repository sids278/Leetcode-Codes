class Solution {
public:
    int mod=1e9+7;
int helper(int ind,int target,int people,vector<int>&group,vector<int>&profit,vector<vector<vector<int>>>&dp)
{
    if(ind==0)
    {

        if(target==0 && profit[ind]>=target && group[ind]<=people )return 2;
        //two ways to take if target is 0, either take it or not, because target is already 0 and we need to get all the ways

        
        else if(profit[ind]>=target && group[ind]<=people || target==0)return 1;//if the first element is greater than equal to target we can take it provided the group index is in bounds with the max people required

        
        else return 0;
    }
    //because we need to travel for 0 targets too,  we need all the combinations
    if(dp[ind][target][people]!=-1)return dp[ind][target][people];
    int notpick = helper(ind-1,target,people,group,profit,dp);
    int pick = 0;
    if(people>=group[ind])
    pick = helper(ind-1,max(target-profit[ind],0),people-group[ind],group,profit,dp);

    return dp[ind][target][people] = (pick%mod+notpick%mod)%mod;
}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(minProfit+1,vector<int>(n+1,-1)));
        return helper(m-1,minProfit,n,group,profit,dp);
     
    }
};