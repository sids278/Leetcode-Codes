class Solution {
public:
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt=0;
        int ans=0;
        int n=nums.size();
        int j=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1)cnt++;
            
            while(cnt>k){
                if(nums[j]%2==1){
                    cnt--;
                    c=0;
                }
                j++;
            }
            
            while(cnt==k && nums[j]%2==0){
                c++;
                j++;
            }
            if(cnt==k)ans+=c+1;
        }
        return ans;
    }
};