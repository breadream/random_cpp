class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> baseRow (n, string(n, '.'));
        solveNQueens(res, baseRow, 0, n);
        return res;
    }
    
private:
    void solveNQueens(vector<vector<string>>& res, vector<string> &baseRow, int row, int colNum)
    {
        if (row == colNum)
        {
            res.emplace_back(baseRow);
            return;
        }
        for (int col = 0; col < colNum; col++)
        {
            if (isValid(baseRow, row, col, colNum))
            {
                baseRow[row][col] = 'Q'; // consider it as Q
                solveNQueens(res, baseRow, row+1, colNum);
                baseRow[row][col] = '.'; // don't consider it as Q
            }
        }
    }
    
    bool isValid(vector<string>& baseRow, int row, int col, int &colNum)
    {
        // check if there's a queen in the same column
        for (int r = 0; r < row; r++)
            if (baseRow[r][col] == 'Q')
                return false;
        
        //  north-west diagonal 
        for (int r = row-1, c = col-1; r >= 0 && c >= 0; --r, --c)
            if (baseRow[r][c] == 'Q')
                return false;
        
        // north-east diagonal 
        for (int r = row-1, c = col+1; r >= 0 && c < colNum; r--, c++)
            if (baseRow[r][c] == 'Q')
                return false;
        
        return true;
    }
};
