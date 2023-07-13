//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    stack<int> st;
    
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs2(it, vis, adj);
            }
        }
    }
    
    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj);
            }
        }
    
        vector<int> transpose[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                transpose[it].push_back(i);
            }
        }
    
        int count = 0;
        while (!st.empty()) {
            int front = st.top();
            st.pop();
            if (!vis[front]) {
                count++;
                dfs2(front, vis, transpose);
            }
        }
    
        return count;
    }

};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends