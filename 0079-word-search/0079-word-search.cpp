class Solution {
public:
    int m,n;
   vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0},  
        {0, -1}, {0, 1} 
    };
    bool backtracking(int index, int i, int j, string &word, vector<vector<char>>& board) {
        if (index == word.length()) return true;
        if (i < 0 || j < 0 || i >= m || j >= n) return false;
        if (board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#'; // Mark the cell as visited
        
        for (auto dir : directions) {
            int newX = i + dir.first;
            int newY = j + dir.second;
            if (backtracking(index + 1, newX, newY, word, board)) return true;
        }

        board[i][j] = temp; // Unmark the cell
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtracking(0, i, j, word, board)) return true;
            }
        }
        
        return false;
    }
};