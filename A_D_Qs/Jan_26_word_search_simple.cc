class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                    if (board[i][j] == word[0] && dfs(board, i, j, 0, word))
                        return true;
        
        return false;
    }
    bool dfs (vector<vector<char>>& board, int i, int j, int wordIdx, string word)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[wordIdx])
            return false;
        if (wordIdx == word.length()-1)
            return true;
        /* up, down, left, right */
        board[i][j] = '\0';
        bool next =  dfs (board, i+1, j, wordIdx+1, word) || dfs (board, i-1, j, wordIdx+1, word) ||
                     dfs (board, i, j-1, wordIdx+1, word) || dfs (board, i, j+1, wordIdx+1, word); 
        board[i][j] = word[wordIdx];
        return next;
    }
};
