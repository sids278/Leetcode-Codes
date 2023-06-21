class Solution {
public:
    long long cos(vector<int>& nums, vector<int>& cost,int m){
        long long ans=0;
        
        for(int i=0;i<nums.size();i++){
            ans += 1LL*(1LL*abs(nums[i]-m)*1LL*cost[i]);
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int s = *min_element(nums.begin(),nums.end());
        int e = *max_element(nums.begin(),nums.end());
        long long ans=LLONG_MAX;
        while(s<=e){
            int m = s+ (e-s)/2;
            long long p = cos(nums,cost,m);
            long long q = cos(nums,cost,m+1);
            if(p<q){
                e = m-1;
                ans = min(ans,p);
            }else{
                s = m+2;
                ans = min(ans,q);
            }
        }
        return ans;
        
    }
};