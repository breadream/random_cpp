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
                    nI++;
                    dfs(grid, i, j);
                }
            }
        }
        return nI;
    }
    // linear scan of 2D grid map, if a node contains '1', the node triggers DFS
    // during consequent dfs, every visited node is set as '0' 
    // the number of nodes that trigger DFS is the number of islands
    void dfs (vector<vector<char>>& grid, int r, int c)
    {
        int nR = grid.size();
        int nC = grid[0].size();
        grid[r][c] = '0';
        if (r-1 >= 0 && grid[r-1][c] == '1')
            dfs(grid, r-1, c);
        if (r+1 < nR && grid[r+1][c] == '1')
            dfs(grid, r+1, c);
        if (c-1 >= 0 && grid[r][c-1] == '1')
            dfs(grid, r, c-1);
        if (c+1 < nC && grid[r][c+1] == '1')
            dfs(grid, r, c+1);
    }
};  
