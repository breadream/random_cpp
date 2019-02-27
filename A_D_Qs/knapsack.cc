struct Item
{
	int w; // weight 
	int v; // value
}

int knapsack (const vector<Item*>& items, int W)
{
	// x, y = # of items from the first, max weight limit
	int [][] dp = new int[items.size()+1][W+1];
	for (int i = 1; i <= items.size(); i++)
	{
		if (items[i]->w > j) // item is heavier than current max limit 
			dp[i][j] = dp[i-1][j]; // get the cached value in previous row
		else // include or exclude 
			dp[i][j] = std::max(dp[i-1][j],
					   dp[i-1][j- items[i-1]->w] + items[i-1]->v);
	}
	return dp[items.size()][W];

}
