class Solution {
public:
    bool valid(int &i,int &j,int &k,vector<int>&nums){
        if(nums[i]+nums[j]>nums[k] && nums[i]+nums[k]>nums[j] && nums[j]+nums[k]>nums[i])return true;
        return false;
    }
    int triangleNumber(vector<int>& nums) {
        //[2,3,4,4]
        
        int n=nums.size();
        if(n<3)return 0;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        int k=2;
        int ans=0;
        

        while (i < n - 2) {
            while (j < n - 1) {
                while (k < n && valid(i, j, k, nums)) {
                    k++;
                }
                if(k>j)ans += k - j - 1;
                j++;
            }
            i++;
            j = i + 1;
            k = j + 1;
        }
        return ans;
    }
};