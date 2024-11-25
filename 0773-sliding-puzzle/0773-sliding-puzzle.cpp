class Solution {
public:
    unordered_map<string, int> seen; 
    string targetHash = "123450";   


    bool valid(int i, int j) {
        return i >= 0 && i < 2 && j >= 0 && j < 3;
    }


    string hashGen(vector<vector<int>>& board) {
        string hash = "";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                hash += to_string(board[i][j]);
            }
        }
        return hash;
    }


    void dfs(int ops, int i, int j, vector<vector<int>>& board) {
        string hashNow = hashGen(board);


        if (hashNow == targetHash) {
            seen[hashNow] = min(seen[hashNow], ops);
            return;
        }


        if (seen.find(hashNow) != seen.end() && seen[hashNow] <= ops) return;


        seen[hashNow] = ops;


        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto [di, dj] : directions) {
            int ni = i + di, nj = j + dj;
            if (valid(ni, nj)) {

                swap(board[i][j], board[ni][nj]);
                dfs(ops + 1, ni, nj, board);

                swap(board[i][j], board[ni][nj]);
            }
        }
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int x, y;


        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }


        seen[targetHash] = INT_MAX;


        dfs(0, x, y, board);


        return seen[targetHash] == INT_MAX ? -1 : seen[targetHash];
    }
};
