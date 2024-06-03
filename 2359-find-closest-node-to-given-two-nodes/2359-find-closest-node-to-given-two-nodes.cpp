class Solution {
public:
    void dfs(int dist, int node, vector<int>& dis, vector<int>& edges, vector<int>& vis) {
        dis[node] = dist;
        vis[node] = 1;
        if (edges[node] != -1 && !vis[edges[node]]) {
            dfs(dist + 1, edges[node], dis, edges, vis);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1(n, -1);
        vector<int> dis2(n, -1);
        vector<int> vis1(n, 0);
        vector<int> vis2(n, 0);

        dfs(0, node1, dis1, edges, vis1);
        dfs(0, node2, dis2, edges, vis2);

        int ans = 1e9;
        int index = -1;

        for (int i = 0; i < n; i++) {
            if (dis1[i] != -1 && dis2[i] != -1) { // Check if both nodes are reachable
                cout << i << "-->" << dis1[i] << " " << dis2[i] << endl;
                if (ans > max(dis1[i], dis2[i])) {
                    index = i;
                    ans = max(dis1[i], dis2[i]);
                }
            }
        }

        if (index == -1) {
            return -1; // No valid meeting node found
        }

        return index;
    }
    
};