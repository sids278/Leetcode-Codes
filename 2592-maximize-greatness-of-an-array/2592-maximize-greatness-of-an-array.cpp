class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i=0, j=0, n=nums.size(), cnt=0;
        while(j<n)
        {
            if(nums[i] >= nums[j]) j++;
            else if(nums[i] < nums[j])
            {
                cnt++;
                i++;
                j++;
            }
        } 
        return cnt;
    }
};