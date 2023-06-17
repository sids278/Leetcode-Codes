//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void dfs(list<pair<int,int>>*adj, vector<bool> &vis, int node, int &mn, int &endNode){
        vis[node]=true;
        for(auto it: adj[node]){
            if(vis[it.second]==false){
                mn=min(mn,it.first); //fINDING tHE mIniMum of all nodes diameter
                endNode=it.second;  //FinDing the LaSt eNdNoDe
                dfs(adj,vis,it.second,mn,endNode);
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d) {
        
        vector<bool> vis(n+1,false);
        list<pair<int,int>> adj[n+1];
        vector<vector<int>> res;
        vector<int> inout(n+1,0);
        
        for(int i=0;i<p;i++){
            adj[a[i]].push_back({d[i],b[i]});
            inout[a[i]]++;  //outgoing, since a is directing to b
            inout[b[i]]--;  //incoming, since b is getting pipe in it
        }
        
        //-1 means it has no outgoing & 1 means it has some outgoing
        
        for(int i=1;i<=n;i++){
            if(inout[i]==1){
                int min=INT_MAX;
                int lastNode=0;
                dfs(adj,vis,i,min,lastNode);
                res.push_back({i,lastNode,min});
            }
        }
        return res;
    }
       
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends