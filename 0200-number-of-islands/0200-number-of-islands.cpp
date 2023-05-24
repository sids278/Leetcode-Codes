class Solution {
public:
//     void DFS(vector<vector<char>>& grid, int i, int j) {
//         // boundary checking
//         if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
//             return;
//         // return if current position is of water or is already visited
//         if(grid[i][j] == '2' || grid[i][j] == '0')
//             return;
        
//         // mark the current as visited
//         grid[i][j] = '2';
        
//         // do DFS in all 4 directions
//         DFS(grid, i+1, j);
//         DFS(grid, i, j-1);
//         DFS(grid, i-1, j);
//         DFS(grid, i, j+1);
//     }
    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if(grid[i][j]=='2'||grid[i][j]=='0')return;
        grid[i][j]='2';
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
       
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};