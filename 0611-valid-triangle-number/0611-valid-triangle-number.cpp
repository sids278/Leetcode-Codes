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
        int count=0;
        for (int i = 0; i < n - 2; ++i) {
            int k = i + 2;
            for (int j = i + 1; j < n - 1 && nums[i] != 0; ++j) {
                while (k < n && nums[i] + nums[j] > nums[k]) {
                    ++k;
                }
                count += k - j - 1;
            }
        }
        return count;
    }
};