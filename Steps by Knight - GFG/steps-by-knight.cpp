//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int X[] = {1, 2, 1, 2, -1, -2, -1, -2};
	    int Y[] = {2, 1, -2, -1, 2, 1, -2, -1};
	    
	    int dp[N + 1][N + 1];
	    memset(dp, -1, sizeof dp);
	    
	    std::queue<pair<int, int>> que;
	    que.push({KnightPos[0], KnightPos[1]});
	    dp[KnightPos[0]][KnightPos[1]] = 0;
	    
	    while(!que.empty()) {
	        auto it = que.front(); que.pop();
	        int x = it.first, y = it.second;
	        for(int i = 0; i < 8; i++) {
	            int nx = x + X[i];
	            int ny = y + Y[i];
	            
	            if(nx < 1 || nx > N || ny < 1 || ny > N || dp[nx][ny] != -1)
	                continue;
	               
	           dp[nx][ny] = 1 + dp[x][y];
	           que.push({nx, ny});
	        }
	    }
	    
	    return dp[TargetPos[0]][TargetPos[1]];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends