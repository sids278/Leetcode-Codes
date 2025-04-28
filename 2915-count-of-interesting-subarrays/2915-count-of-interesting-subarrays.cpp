class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> mappa;
        mappa[0] = 1;
        long long presum = 0, cnt = 0;
        for(int num: nums){
            if(num % modulo == k)
                presum++;
            int rem = (presum - k) % modulo;
            if(rem < 0) rem += modulo;
            cnt +=  mappa[rem];
            mappa[presum % modulo]++;
        }
        return cnt;
    }
};
