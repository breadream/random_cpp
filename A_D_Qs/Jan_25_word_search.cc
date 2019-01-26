class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    // mark the visited cell  
                    board[i][j] = '\0';
                    if (check(board, i, j, 1, word))
                        return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, int i, int j, int wordIdx, string word)
    {
        if (wordIdx == word.length())
            return true;
        /* up, down, left, right */
        if (i > 0 && board[i-1][j] == word[wordIdx])
        {
            board[i-1][j] = '\0';
            if (check(board, i-1, j, wordIdx+1, word))
                return true;
            board[i-1][j] = word[wordIdx];
        }
        if (i < board.size()-1 && board[i+1][j] == word[wordIdx])
        {
            board[i+1][j] = '\0';
            if (check(board, i+1, j, wordIdx+1, word))
                return true;
            board[i+1][j] = word[wordIdx];
        }
        if (j > 0 && board[i][j-1] == word[wordIdx])
        {
            board[i][j-1] = '\0';
            if (check(board, i, j-1, wordIdx+1, word))
                return true;
            board[i][j-1] = word[wordIdx];
        }
        if (j < board[i].size()-1 && board[i][j+1] == word[wordIdx])
        {
            board[i][j+1] = '\0';
            if(check(board, i, j+1, wordIdx+1, word))
                return true;
            board[i][j+1] = word[wordIdx];
        }
        return false;
    }
};
