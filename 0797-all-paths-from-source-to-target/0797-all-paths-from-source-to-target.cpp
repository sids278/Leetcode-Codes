class Solution {
public:
    void dfs(vector<int>&temp,vector<vector<int>>&ans,vector<int>adj[],vector<int>&vis,int n,int node){
        if(node == n-1){
            ans.push_back(temp);
            return;
        }
        for(auto i:adj[node]){
                temp.push_back(i);
                dfs(temp,ans,adj,vis,n,i);
                temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>vis(n,0);
        temp.push_back(0);
        dfs(temp,ans,adj,vis,n,0);
        return ans;
    }
};