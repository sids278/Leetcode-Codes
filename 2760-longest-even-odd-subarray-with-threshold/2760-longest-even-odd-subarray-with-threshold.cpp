class Solution {
public:
    
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
       
        int last=INT_MAX;
        int cnt=0;
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]>threshold||(i > 0 && (nums[i] % 2) == (nums[i-1] % 2))){
                cnt=max(cnt,i-last);
                last=INT_MAX;
            }
            if(last==INT_MAX && nums[i]<=threshold&&nums[i]%2==0)last=i;
            i++;
        }
        // forr the last index we couldnt calculate because we exit the outside loop
        cnt=max(cnt,i-last);
        return cnt;
        
    }
};