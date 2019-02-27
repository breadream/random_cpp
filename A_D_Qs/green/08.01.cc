int countWays (int n)
{
	vector<int> memo (n+1, -1);
	return countWays(n, memo);
}

int countWays(int n, vector<int>& memo)
{
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else if (memo[n] > -1)
		return memo[n];
	else
		memo[n] = countWays(n-1, memo) 
				+ countWays(n-1, memo) + countWays(n-1, memo);
	return memo[n];
}

int countWays (int n, const vector<int>& steps)
{
	if (n == 0)
		return 1;

	int sum = 0;

	for (const int i : steps)
		if (n >= i)
			sum += countWays(n-i, steps);

	return sum;
}

int countWays (const int n)
{
	int dp [n+1];
	dp[0] = 1; // 1 instead of 0 because n == 0 means we've already found a path
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

	return dp[n];
}
