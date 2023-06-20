class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
       
        int n = nums.size();
        vector<int> avg(n,-1);
        if(2*k+1>n) return avg;
        long long sum=0;
        int z=0;
        while(z<2*k && z<n){
            sum+=nums[z++];
        }
        for(int i=k;i<n && n-i-1>=k;i++){
            sum += nums[i+k];
            avg[i] = sum/(2*k+1);
            sum -= nums[i-k];
        }
        return avg;
    }
};