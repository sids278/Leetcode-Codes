class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0;
        int cnt=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1)cnt++;
            
            while(cnt>1){
                if(nums[left]!=1)cnt--;
                left++;
            }
            ans=max(ans,i-left);
        }
        return ans;
    }
};