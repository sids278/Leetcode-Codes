class Solution {
public:
    long f(long el,unordered_map<long,long>&dp){
        if(el==0)return INT_MAX;
        if(el==1)return 0;
        if(dp.find(el)!=dp.end())return dp[el];
        if(el%2==0)return 1+f(el/2,dp);
        return 1+min(f(el-1,dp),f(el+1,dp));
    }
    int integerReplacement(int n) {
        long  x=1;
        int po=0;
        while(x<n){
            x=x*2;
            po+=1;
        }
        cout<<x/2;
        po--;
        unordered_map<long,long>dp;
        x=x/2;
        dp[1]=1;
        while(x>1){
            dp[x]=po;
            po--;
            x=x/2;
        }
        return f(n,dp);
        
    }
};