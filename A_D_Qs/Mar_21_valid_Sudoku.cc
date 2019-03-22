    bool isValidSudoku(vector<vector<char>>& board) {
        // set all as unvisited
        vector<vector<int>> rowCheck (9, vector<int>(9, 0));
        vector<vector<int>> colCheck (9, vector<int>(9, 0));
        vector<vector<int>> subCheck (9, vector<int>(9, 0));
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    int num = (board[i][j] - '0') - 1;
                    int sub = (i/3) * 3 + (j / 3);
                    if (rowCheck[i][num] || colCheck[j][num] || subCheck[sub][num])
                        return false;
                    // set number as visited
                    rowCheck[i][num] = colCheck[j][num] = subCheck[sub][num] = 1;
                }
            }
        }
        return true;
    }
