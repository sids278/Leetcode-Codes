class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f=INT_MAX;
        int s=INT_MAX;
        for(auto&n:nums){
            if(n<=f){
                f=n;
            }
            else if(n<=s){
                s=n;
            }
            else return true;
        }
        return false;
    }
    
};