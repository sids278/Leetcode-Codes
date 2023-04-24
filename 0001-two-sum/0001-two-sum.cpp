class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
		for (auto firstCount = 0; firstCount < nums.size(); ++firstCount) {
			for (auto secondCount = firstCount + 1; secondCount < nums.size(); ++secondCount) {
				if (target == (nums[firstCount] + nums[secondCount])) {
					temp.push_back(firstCount);
					temp.push_back(secondCount);
					return temp;
				}
			}
		}
		return temp;
    }
};