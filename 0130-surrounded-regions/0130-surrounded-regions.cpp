class Solution {
public:
    int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
    bool valid(int i,int j,int m,int n){
        if(i<0||j<0||i>=m||j>=n)return false;
        return true;
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++){
                if(i==0||i==m-1||j==0||j==n-1){
                    if(board[i][j]=='O')q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            int i=f.first;
            int j=f.second;
            board[i][j]='N';
            for(int d=0;d<4;d++){
                int newI=i+dir[d][0];
                int newJ=j+dir[d][1];
                if(valid(newI,newJ,m,n)&&board[newI][newJ]=='O')q.push({newI,newJ});
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++){
                if(board[i][j]=='N')board[i][j]='O';
                else board[i][j]='X';
            }
            
        }
        
        
    }
};