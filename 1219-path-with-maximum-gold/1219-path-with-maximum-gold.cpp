class Solution {
public:
    priority_queue<pair<int,pair<int,int>>> pq;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> gq;
    int ans = 0;
    
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }
        
        visited[i][j] = 1;
        int maxGold = 0;
        
        maxGold = max(maxGold, dfs(i + 1, j, grid, visited));
        maxGold = max(maxGold, dfs(i - 1, j, grid, visited));
        maxGold = max(maxGold, dfs(i, j + 1, grid, visited));
        maxGold = max(maxGold, dfs(i, j - 1, grid, visited));
        
        visited[i][j] = 0;
        return grid[i][j] + maxGold;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    gq.push({grid[i][j], {i, j}});
                    if (gq.size() > 25) gq.pop();
                }
            }
        }
        
        while (!gq.empty()) {
            auto gold = gq.top();
            gq.pop();
            pq.push(gold);
        }
        
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            vector<vector<int>> visited(m, vector<int>(n, 0));
            int x = t.second.first;
            int y = t.second.second;
            ans = max(dfs(x, y, grid, visited), ans);
        }
        
        return ans;
    }
};
