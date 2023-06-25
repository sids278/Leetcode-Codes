class Solution {
public:
    // for(int i = 0; i < 3; i++)
    //     {
    //         for(auto c : board[i])
    //         {
    //             if(c == 'X') nx++;
    //             else if(c == 'O') no++;
    //         }
    //     }
    //     if(!(nx == no || nx == no + 1)) return false;
    //     else if(nx == no)
    //     {
    //         return !isWin(board, 'X');
    //     }
    //     else
    //     {
    //         return !isWin(board, 'O');
    //     }
    //     return true;
    bool isWin(vector<string> &board, char c)
    {
        for(int i = 0; i < 3; i++)
        {
            //checking the row
            if(board[i][0] == c && \
               board[i][0] == board[i][1] && board[i][1] == board[i][2])
            {
                return true;
            }
            //checking the column
            else if(board[0][i] == c && \
                    (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            {
                return true;
            }
        }
        //checkint both the diagonals
        if(board[0][0] == c && \
           board[1][1] == board[0][0] && board[2][2] == board[0][0])
        {
            return true;
        }
        else if(board[0][2] == c && \
           board[1][1] == board[0][2] && board[2][0] == board[0][2])
        {
            return true;
        }
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int nx,no=0;
        for(int i=0;i<3;i++){
            for(auto c : board[i])
            {
                if(c == 'X') nx++;
                else if(c == 'O') no++;
            }
        
        }
        if(!(nx==no||nx==no+1))return false;
        else if(nx == no)
        {
            return !isWin(board, 'X');
        }
        else
        {
            return !isWin(board, 'O');
        }
        return true;
    }
};