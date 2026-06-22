class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        // adj[node] = {neighbor, weight}
        // weight = 0 means edge goes node→neighbor (correct from node's side)
        // weight = 1 means edge goes neighbor→node (needs reversal to go outward)
        vector<vector<pair<int,int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], 0}); // original edge e[0]→e[1], costs 0 from e[0]
            adj[e[1]].push_back({e[0], 1}); // reversed view, costs 1 from e[1]
        }

        vector<int> ans(n, 0);

        // Step 1: DFS from node 0 to compute ans[0]
        // (how many reversals to reach all nodes from 0)
        //here we store one ans for any node and then for other nodes we will be using this further down
        function<void(int, int)> dfs1 = [&](int node, int parent) {
            for (auto [next, cost] : adj[node]) {
                if (next == parent) continue;
                ans[0] += cost;       // cost = 1 means edge points wrong way
                dfs1(next, node);
            }
        };
        dfs1(0, -1);

        // Step 2: Reroot — propagate ans from 0 to every other node in O(n)
        function<void(int, int)> dfs2 = [&](int node, int parent) {
            for (auto [next, cost] : adj[node]) {
                if (next == parent) continue;
                // cost == 0 means edge is node→next (correct from node, wrong from next)
                // cost == 1 means edge is next→node (wrong from node, correct from next)
                ans[next] = ans[node] + (cost == 0 ? 1 : -1);
                dfs2(next, node);
            }
        };
        dfs2(0, -1);

        return ans;
    }
};