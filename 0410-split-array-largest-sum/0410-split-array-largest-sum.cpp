class Solution {
public:
    bool valid(vector<int>&nums,int k,int m){
        int n=nums.size();
        int cnt=0;
        int ans=1;
        for(int i=0;i<n;i++){
            if(nums[i]+cnt<=m){
                cnt+=nums[i];
            }
            else{
                ans+=1;
                cnt=nums[i];
            }
        }
        return ans<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int r=accumulate(nums.begin(),nums.end(),0);
        auto maxEle=max_element(nums.begin(),nums.end());
        int l=*maxEle;
        int mid;
        int ans=0;
        while(l<=r){
            mid=(l+r)/2;
            if(valid(nums,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};