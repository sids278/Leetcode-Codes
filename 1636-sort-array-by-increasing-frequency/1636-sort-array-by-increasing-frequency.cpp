class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++)hashmap[nums[i]]++;
        priority_queue<pair<int, int>> pq;
        for (auto it : hashmap)pq.push({-it.second, it.first}); 
        vector<int> ans;
        while (!pq.empty()) {
            for(int i=0;i<-pq.top().first;i++)ans.emplace_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};