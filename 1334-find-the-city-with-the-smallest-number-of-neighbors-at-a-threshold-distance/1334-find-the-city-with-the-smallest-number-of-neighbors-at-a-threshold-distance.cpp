class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>>dis(n,vector<long long>(n,-1));
        for(auto x:edges){
            dis[x[0]][x[1]]=x[2];
            dis[x[1]][x[0]]=x[2];
        }
        for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dis[i][j] == -1) {
					dis[i][j] = 1e9;
				}
				if (i == j) dis[i][j] = 0;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dis[i][j] = min(dis[i][j],
					                   dis[i][k] + dis[k][j]);
				}
			}
		}
        int city=-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
               cout<<dis[i][j]<<" ";
                if(i!=j && dis[i][j]<=distanceThreshold)cnt++;
            }
            
            if(ans>=cnt){
                ans=cnt;
                city=i;
            }
           
        }
        return city;
    }
};