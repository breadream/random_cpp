class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int nR = grid.size();
        if (nR == 0)
            return 0;
        int nC = grid[0].size();
        int nI = 0;
        for (int i = 0; i < nR; i++)
        {
            for (int j = 0; j < nC; j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0'; // mark it as visited
                    nI++;
                    queue<pair<int, int>> adj;
                    adj.push({i, j}); // starting from the source
                    while (!adj.empty())
                    {
                        auto curr = adj.front();
                        adj.pop();
                        int r = curr.first;
                        int c = curr.second;    
                            
                        if (r-1 >= 0 && grid[r-1][c] == '1')
                        {
                             grid[r-1][c] = '0';
                             adj.push({r-1, c});
                        }
                        if (r+1 < nR && grid[r+1][c] == '1')
                        {
                             grid[r+1][c] = '0';
                             adj.push({r+1, c});
                        }
                        if (c-1 >= 0 && grid[r][c-1] == '1')
                        {
                            grid[r][c-1] = '0';
                            adj.push({r, c-1});
                        }
                        if (c+1 < nC && grid[r][c+1] == '1')
                        {
                            grid[r][c+1] = '0';
                            adj.push({r, c+1});
                        }
                    }
                }
            }
        }
        return nI;
    }
};  
