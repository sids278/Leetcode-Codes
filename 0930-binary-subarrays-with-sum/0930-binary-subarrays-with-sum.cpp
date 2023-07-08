class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0;
        int r=0;
        int n=nums.size();
        int cnt=0;
        int sum=0;
        int ans=0;
        while(r<n){
            sum+=nums[r];
            cout<<sum<<cnt<<endl;
            while(sum>goal && l!=r){
                sum-=nums[l];
                l++;
                cnt=0;
                
            }
            while(sum==goal && nums[l]==0 && l!=r){
                cnt++;
                l++;
            }
            
            if(sum==goal){ans+=cnt+1;}
            
            r++;
            
        }
        return ans;
    }
};