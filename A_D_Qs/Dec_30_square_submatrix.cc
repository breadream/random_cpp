[1, 1, 1, 0]
[1, 1, 1, 0]
[1, 1, 1, 0]
[0, 0, 0, 0]

[1, 1, 1, 0]
[1, 2, 2, 0]
[1, 2, 3, 0]
[0, 0, 0, 0]

// bottom right corner is the vertex of each square 

int square_submatrix (const vector<vector<int>& arr)
{
	// cannot group these because if x is 0, y would fail
	int x = arr.size(); 
	if (x == 0) return 0;
	int y = arr[0].size();
	if (y == 0) return 0;
	vector<vector<int>> sizes (x, vector<int>(y, 0)); // sizes of each cell
	int max = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (i == 0 || j == 0) // set boundaries 
				sizes[i][j] = arr[i][j];
			else if (arr[i][j] == 1)
				sizes[i][j] = min(sizes[i-1][j-1], min(sizes[i][j-1], sizes[i][j-1]));
			max = (max < sizes[i][j]) ? sizes[i][j] : max;
		}
	}
	return max;
}

