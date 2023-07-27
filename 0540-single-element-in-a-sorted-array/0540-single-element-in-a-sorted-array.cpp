class Solution {
public:
    
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=1; int high=n-2;
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) // single element
        return nums[mid];


        // even ---> odd (Left half pairs)
        if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1])) //We are in left half
        {
            // eliminate left half
            low=mid+1;
        } 
        // odd----->even (right half pairs)
        else // right half contains single element
        {   
            // eliminate the left half
            high=mid-1;
        }
      
    }

    return -1;;
    }
};