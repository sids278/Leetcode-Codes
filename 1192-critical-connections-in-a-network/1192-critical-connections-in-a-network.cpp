class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int node ,int parent, vector<int>&vis,vector<int>&tin,vector<int>&low, int &timer,vector<vector<int>>&adj){
        vis[node]=1;
        low[node]=tin[node]=timer++;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,node,vis,tin,low,timer,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    ans.push_back({node,it});
                }
            }
            else if(it!=parent){
                low[node]=min(low[node],tin[it]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            int x=connections[i][0];
            int y=connections[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int>vis(n,0);
        vector<int>tin(n,0);
        vector<int>low(n,0);
        int timer=0;
        dfs(0,-1,vis,tin,low,timer,adj);
        return ans;
        
        
        
    }


};