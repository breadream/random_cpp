class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == word[0]) 
                {
                    board[i][j] = '\0';
                    if (check(board, word, 1, i, j))
                        return true;
                    board[i][j] = word[0];
                }
        return false;
    }
    
    bool check(vector<vector<char>> board, string word, int wordIdx, int i, int j)
    {
        if (wordIdx == word.length())
            return true;
        if (i > 0 && board[i-1][j] == word[wordIdx]) // up
        {
            board[i-1][j] = '\0';
            if (check(board, word, wordIdx+1, i-1, j))    
                return true;
            board[i-1][j] = word[wordIdx];
        }
         if (j < board[i].size()-1 && board[i][j+1] == word[wordIdx])    
        {
            board[i][j+1] = '\0';
            if (check(board, word, wordIdx+1, i, j+1)) // right
                return true;
            board[i][j+1] = word[wordIdx];
        }
        if (i < board.size()-1 && board[i+1][j] == word[wordIdx]) // down
        {
            board[i+1][j] = '\0';
            if (check(board, word, wordIdx+1, i+1, j))
                return true;
            board[i+1][j] = word[wordIdx];
        }
        if (j > 0 && board[i][j-1] == word[wordIdx]) // left
        {
            board[i][j-1] = '\0';
            if (check(board, word, wordIdx+1, i, j-1))   
                return true;
            board[i][j-1] = word[wordIdx];
        }
       
        return false;
    }
};
