class Solution {
public:
    int check(int i,int j,vector<vector<int>>& board){
        int m=board.size();
        int n=board[0].size();
        if(i<0||j<0||i>=m||j>=n)return 0;
        if(board[i][j]==1){
            return 1;
        }
        return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> temp = board;  // Create a copy of the board to store the updated state
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int directions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1},
                                         { 0, -1},         { 0, 1},
                                         { 1, -1}, { 1, 0}, { 1, 1} };
                int x = 0;
                for (auto& dir : directions) {
                    int newRow = i + dir[0];
                    int newCol = j + dir[1];
                    x += check(newRow, newCol, board);
                }
                if (board[i][j] == 1) {
                    if (x < 2 || x > 3) temp[i][j] = 0;
                } else {
                    if (x == 3) temp[i][j] = 1;
                }
            }
        }
        
        board = temp; 
    }
};