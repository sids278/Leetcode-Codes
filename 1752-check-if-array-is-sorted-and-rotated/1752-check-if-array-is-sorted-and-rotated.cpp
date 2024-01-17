class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                if(cnt>0)return false;
                else cnt=1;
            }
            
        }
        if(cnt==0)return nums[0]<=nums[nums.size()-1];
        return nums[0]>=nums[nums.size()-1];
    }
};