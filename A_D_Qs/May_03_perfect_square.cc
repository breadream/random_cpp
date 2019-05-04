    int numSquares(int n) {
        if (n <= 3)
            return n;
        
        // dp[i] = the least number of perfect square numbers tha sum to i
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j*j <= i; j++)
                dp[i] = min(dp[i], dp[i-j*j]+1);
        }
        return dp[n];
    }
