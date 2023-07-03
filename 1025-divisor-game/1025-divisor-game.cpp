class Solution {
public:
    
    
    bool divisorGame(int n) {
       if(n==1){
           return false;
       }
       vector<int> dp(n+1,0);
        for(int i=2;i<n+1;i++){
            for(int j=1;j<sqrt(i);j++){
                if(i%j==0 && dp[i-j]==0){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n]==1;
        
    }
};