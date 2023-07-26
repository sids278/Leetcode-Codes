class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int cnt=0;
        int ans=0;
        while(i<=j && j<n){
            if(nums[j]==0)cnt++;
            
            if(cnt>k){
                cout<<ans<<i<<j<<endl;
                ans=max(ans,j-i);
                while( i<=j && cnt>k){
                    if(nums[i]==0)cnt--;
                    i++;
                }
            }
            j++;
            
        }
        ans=max(ans,j-i);
        return ans;
    }
};