class Solution {
public:

    int wiggleMaxLength(vector<int>& nums) {
        int inc=1;
        int dec=1;
        // intially kept one for both because pehla element toh can be mde part of any of the two so pehla element leke toh dono bna skte tob intially one
        //here the inc and dec variables signify the length of increasing and decreasing subsequence -->increasing subsequence means jiska the last node was increasing so when we encounter a place where nums[i]-nums[i-1]<0 means ab decreasing subsequqence aa gya so add one node to the maximum icreasing subsequence we had and similarly in the other case and finally we compare the lengths of both the increasing and decreasing subsequences ki length and take max
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>0){
                inc=dec+1;
            }
            else if(nums[i]-nums[i-1]<0){
                dec=inc+1;
            }
        }
        return max(inc,dec);
    }
};