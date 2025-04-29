class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
      long long ans=0;
      long long score=0;
      int i=0;
      int j=0;
      int n=nums.size();
      int l=0;
      long long sum=0;
      while(i<n && j<n){
        sum+=nums[j];
        // if(nums[j]<k)ans++;
        
        
        while(i <= j && sum * (j - i + 1) >= k){
            sum-=nums[i];
            
            i++;
            
        }
        ans += (j - i + 1);
        // l++;
        j++;
      }
      return ans;
    
    }
};