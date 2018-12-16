class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] == word[0] && check(board, word, 0, i, j))
                    return true;
                
        return false;
    }
    
    bool check(vector<vector<char>> board, string word, int wordIdx, int i, int j)
    {
        if (wordIdx == word.length() || word.length() < 2)
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size())
            return false;
        if (word[wordIdx] == board[i][j])
        {
            char curr_char = board[i][j];
            board[i][j] = '$';
            if (check(board, word, wordIdx+1, i+1, j) || check(board, word, wordIdx+1, i-1, j) ||
                check(board, word, wordIdx+1, i, j-1) || check(board, word, wordIdx+1, i, j+1))
                return true;
            board[i][j] = curr_char;
        }
        return false;
    }
        
};
