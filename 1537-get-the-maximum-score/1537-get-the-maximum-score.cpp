class Solution {
public:
    unordered_map<string, long long> dp;
	long long solve(int i, int j, bool is1, vector<int>& nums1, vector<int>& nums2) {
		string key = to_string(i) + "_" + to_string(j) + "_" + to_string(is1);

		if(dp.count(key) > 0)
			return dp[key];

		if(is1) {
			if(i == nums1.size())
				return dp[key] = 0;

			if(j == nums2.size() || nums1[i] < nums2[j]) {
				return dp[key] = (nums1[i] + solve(i+1,j,true,nums1,nums2));
			}else if(nums1[i] == nums2[j]) {
				//change lane
				long long x = solve(i+1,j,false,nums1,nums2);
				//do not change lane
				long long y = (nums1[i] + solve(i+1,j,true,nums1,nums2));
				return dp[key] = max(x,y);
			}else{
				while(j < nums2.size() && nums2[j] < nums1[i]) {
					j++;
				}
				return dp[key] = solve(i,j,true,nums1,nums2);
			}
		}else{
			if(j == nums2.size())
				return dp[key] = 0;

			if(i == nums1.size() || nums2[j] < nums1[i]){
				return dp[key] = (nums2[j] + solve(i,j+1,false,nums1,nums2));
			}else if(nums2[j] == nums1[i]) {
				// do not change lane
				long long x = (nums2[j] + solve(i,j+1,false,nums1,nums2));
				// change lane
				long long y = solve(i,j+1,true,nums1,nums2);
				return dp[key] = max(x,y);
			}else{
				while(i < nums1.size() && nums1[i] < nums2[j]) {
					i++;
				}
				return dp[key] = solve(i,j,false,nums1,nums2);
			}
		}
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        dp.clear();
		long long one=solve(0,0,true,nums1,nums2);
        long long two=solve(0,0,false,nums1,nums2);
        cout<<one<<two;
		return max(one,two) % 1000000007;
    }
};