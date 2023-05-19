class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n,1);
        int maxI=-1;
        int lastIndex=-1;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<=i-1;j++){
                
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
                
            }
           
            if(dp[i]>maxI){
                lastIndex=i;
                maxI=dp[i];
            }
        }
        cout<<hash[lastIndex];
        vector<int>fin;
        while(hash[lastIndex]!=lastIndex){
            fin.push_back(nums[lastIndex]);
            lastIndex=hash[lastIndex];
        }
        fin.push_back(nums[lastIndex]);
        return fin;
        
        
    }
};