class Solution {
public:
    // Direction array: right, down, left, up
    const vector<int> d = {0, 1, 0, -1, 0};

    bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));

        // Use tuple to store (time, i, j)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // Start at (0, 0) with time 0
        pq.emplace(0, 0, 0);
        time[0][0] = 0;

        while (!pq.empty()) {
            auto [t, i, j] = pq.top(); pq.pop();

            if (i == n - 1 && j == m - 1)
                return t;

            // Traverse all four directions
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m)) continue;

                int nextTime = max(t, moveTime[r][s]) + 1;

                if (nextTime < time[r][s]) {
                    time[r][s] = nextTime;
                    pq.emplace(nextTime, r, s);
                }
            }
        }

        return -1;
    }
};