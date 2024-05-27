class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        vector<int> degree(n, 0);
        unordered_map<int, unordered_set<int>> connected;


        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            degree[u]++;
            degree[v]++;
            connected[u].insert(v);
            connected[v].insert(u);
        }

        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = degree[i] + degree[j];
                if (connected[i].find(j) != connected[i].end()) {
                    rank--; 
                }
                ans = max(ans, rank);
            }
        }

        return ans;
    }
};