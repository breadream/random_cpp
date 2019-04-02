int maxPossibleCoin (const vector<vevtor<int>>& matrix)
{
	int max = 0;
	int row = matrix.size();
	int col = matrix[0].size();
	int dp [row+1][col+1];
	memset(dp, 0, sizeof dp);
	dfs (matrix, dp, 0, 0, 0);

	return dp[row][col];
}


void dfs (const vector<vector<int>>& matrix, int[][]& dp, int row, int col, int sum)
{
	if (row == matrix.size() && col == matrix[0].size())
		return;

	sum += matrix[i][j];

	dp[i][j] = max(sum, dp[i][j]);

	if (row+1 < matrix.size())
		dfs (matrix, dp, row+1, col, sum);

	if (col+1 < matrix[0].size())
		dfs (matrix, dp, row, col+1, sum);
}
