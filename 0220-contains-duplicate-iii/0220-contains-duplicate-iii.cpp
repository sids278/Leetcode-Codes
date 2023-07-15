class Solution {
public:
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        // here we can use a set or a simple vector to push and then we use lower bound simply to get the lowest value near to nums[i]-t and we maintain the window size=k by deleting the i-k+1 element
        // here i will use set kyuki erase krna easy hota ig and duplicacy in window bhi handle hojegi and ordering bhi sorted hogi rather than. vector so use set-->for sorted order and lower bound use
        
    
        int k=indexDiff;
        int t=valueDiff;
        int n=nums.size();
        set<int>s;
        for(int i=0;i<n;i++){
            if(i>k){
                s.erase(nums[i-k-1]);
            }
            auto pos=s.lower_bound(nums[i]-t);
            if(pos!=s.end() && abs(*pos-nums[i])<=t)return true;
            s.insert(nums[i]);
        }
        return false;

        
    }
};