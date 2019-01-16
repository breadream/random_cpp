// Top down approach

int coinChange(vector<int>& coins, int amount) 
{
	vector<int> cache (amount.size()+1, -1);
	return coinChange(coins, amount, cache);
}

int coinChange(vector<int>& coins, int amount, vector<int>& cache)
{
	if (cache[amount] >= 0)
		return cache[amount];
	int minCoins = INT_MAX;
	
	// find the best coin
	for (int coin : coins)
	{
		if (amount - coin >= 0)
		{
			int currMinCoins = coinChange(coins, amount - coin, cache); 
			if (currMinCoins < minCoins)
				minCoins = currMinCoins;
		}
	}
	// save the value into the cache
	cache[c] = minCoins + 1;
	return cache[c];
}

// Bottom up approach

int coinChange (vector<int>& coins, amount)
{
	vector<int> cache(amount+1, -1);
	cache[0] = 0; // 0 ways to make amount of 0
	for (int i = 1; i <= amount; i++)
	{
		int minCoins = INT_MAX; 
		// Try removing each coin from the total
    	// and see which requires the fewest
    	// extra coins
		for (int coin : coins)
		{
			if (i - coin >= 0)
			{
				int currCoins = cache[i-coin] + 1;
				if (currCoins < minCoins)
					minCoins = currCoins;
			}
		}
		cache[i] = minCoins;
	}
	return cache[amount];

}

