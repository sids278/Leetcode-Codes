class Solution {
public:
    int gmax = 0;
    int gCount=0;
    void maxOr(int curr, int indx, vector<int>& nums) {
        
        if(curr==gmax){
            gCount++;
        }
        else if(gmax<curr)gCount=1;
        gmax = max(gmax, curr);
        for (int i = indx; i < nums.size(); i++) {
            maxOr(curr | nums[i], i + 1, nums);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        maxOr(0, 0, nums);
        return gCount;

    }
};