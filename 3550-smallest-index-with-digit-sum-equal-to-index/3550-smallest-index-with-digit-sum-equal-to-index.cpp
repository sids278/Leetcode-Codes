class Solution {
public:
    int sumConvert(int x){
        if(x==0)return 0;
        int nextChar=x/10;
        int rem=x%10;
        return sumConvert(nextChar)+rem;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ans1=sumConvert(nums[i]);
            if(i==ans1)return i;
        }
        return -1;
    }
};