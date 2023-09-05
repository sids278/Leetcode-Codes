class Solution {
public:
    // doing this by meet in the middle
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
		vector<vector<int>> left(n+1, vector<int>()), right(n+1, vector<int>());
		function<void(int, int, int, int, vector<vector<int>>&)> generate;

		int total = accumulate(begin(nums), end(nums), 0);
		int target = total / 2;

		generate = [&](int i, int s, int total, int len, vector<vector<int>>& v){
			if(i-s >= n){
				v[len].push_back(total);
				return;
			}

			generate(i+1, s, total, len, v);            
			generate(i+1, s, total+nums[i], len+1, v);

		};

		generate(0,0,0,0,left);        
		generate(n,n,0,0,right);

		for(auto& v : right) 
			sort(begin(v), end(v));

		int ans = INT_MAX;
		for(int i=0; i<=n; ++i){
			for(int& L : left[i]){
				int key = target - L;
				auto iter = lower_bound(right[n-i].begin(), right[n-i].end(), key);
				if(iter == right[n-i].end()) iter--;

				int lsum = L + *iter;
				int rsum = total - lsum;
				int diff = abs(lsum - rsum);

				if(diff == 0) 
					return 0;
				ans = min(ans, diff);
			}
		}

		return ans;
    }
};