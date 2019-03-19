class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() == 0)
            return;
        solve(board);
    }
    
    bool solve (vector<vector<char>>& board)
    {
        for (int r = 0; r < board.size(); r++)
        {
            for (int c = 0; c < board[0].size(); c++)
            {
                if (board[r][c] == '.')
                {
                    for (char num = '1'; num <= '9'; num++)
                    {
                        if (isValid(board, r, c, num))
                        {
                            board[r][c] = num;
                            
                            if (solve(board))
                                return true;
                            else 
                                board[r][c] = '.';
                        }
                    }
                    return false;
                 }
             }
        }
        return true;
    }
    
    bool isValid(const vector<vector<char>>& board, int r, int c, char num)
    {
        for (int i = 0; i < 9; i++)
        {
            char rowChar = board[i][c];
            if (rowChar != '.' && rowChar == num) // row check
                return false;
            
            char colChar = board[r][i];
            if (colChar != '.' && colChar == num) // col check
                return false;
            
            char subboard = board[3 * (r/3) + i/3][3 * (c/3) + i % 3]; 
            if (subboard != '.' && subboard == num)
                return false;
        }
        return true;
    }
};
