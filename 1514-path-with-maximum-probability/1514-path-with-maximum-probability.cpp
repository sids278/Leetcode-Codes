class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double,int>>pq;
        
        vector<bool>vis(n,false);
            
        vector<vector<pair<int,double>>>adj(n);
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
       
        
        
        vector<double>prob(n,0);
        prob[start]=1;
        
        pq.push({1,start});
        
        while(!pq.empty())
        {
            pair<double,int>p = pq.top();
            pq.pop();
            
            for(auto it:adj[p.second])
            {
                   if(!vis[it.first])
                   {
                       if(prob[it.first]<prob[p.second]*it.second)
                       {
                           prob[it.first]=prob[p.second]*it.second;
                           pq.push({prob[it.first],it.first});
                       }
                   }
               
            }
            vis[p.second]=true;
        }
        
        
        
        return prob[end];
    }
        
    
};