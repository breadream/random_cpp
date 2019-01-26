class Solution {
public:
    // [second bit, first bit] = [next state, current state]
    // next <- current
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty())
            return;
        int m = board.size(), n = board[0].size();
         
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int liveNBH = getLiveNBH(board, i, j, m, n);
                // since the default second bit is 0, 
                // we don't have to consider 1st and 3rd conditions
                if (board[i][j] == 1 && (liveNBH == 2 || liveNBH == 3))
                    board[i][j] = 3; // 01 -> 11 
                if (board[i][j] == 0 && liveNBH == 3)
                    board[i][j] = 2; // 00 -> 10
            }
        }
        
        // we only need the second state 
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] >>= 1;
    }
private:
    // get the number of live neighbors
    int getLiveNBH(const vector<vector<int>>& cells, int i, int j, int m, int n)
    {
        int numLiveCells = 0; 
        // to include neighboring element  
        for (int x = max(i-1, 0); x <= min(i+1, m-1); x++)
            for (int y = max(j-1, 0); y <= min(j+1, n-1); y++)
                numLiveCells += cells[x][y] & 1; // only the current state
        
        numLiveCells -= cells[i][j] & 1; // subtract the current cell if it is live 
        return numLiveCells;
    }
    
};
