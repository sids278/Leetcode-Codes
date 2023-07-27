class Solution {
public:
    int search(vector<int>&nums,int l,int r){
        if(l>r)return -1;
        int n=nums.size();
        int mi;
       cout<<l<<" "<<r<<endl;
            mi=(l+r)/2;
            if(mi>0 && mi<n-1&&nums[mi]>nums[mi-1] && nums[mi]>nums[mi+1])return mi;
            if(search(nums,l,mi-1)!=-1)return  search(nums,l,mi-1);
            return search(nums,mi+1,r);
        
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        
        if(search(nums,0,n-1)==-1)return nums[n-1]>nums[0]?n-1:0;
        return search(nums,0,n-1);
    }
};