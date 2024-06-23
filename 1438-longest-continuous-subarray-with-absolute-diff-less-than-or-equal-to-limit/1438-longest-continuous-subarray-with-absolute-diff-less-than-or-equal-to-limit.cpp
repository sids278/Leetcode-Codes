class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0, j = 0;
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

        for (int i = 0; i < nums.size(); i++) {
            maxHeap.push({nums[i], i});
            minHeap.push({nums[i], i});

            while (maxHeap.top().first - minHeap.top().first > limit) {
                j = min(maxHeap.top().second, minHeap.top().second) + 1;

                while (maxHeap.top().second < j) {
                    maxHeap.pop();
                }

                while (minHeap.top().second < j) {
                    minHeap.pop();
                }
            }

            ans = max(ans, i - j + 1);
        }
        
        return ans;
        
    }
};