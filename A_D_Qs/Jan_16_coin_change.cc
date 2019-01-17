class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = min coins to make up to amount i
        vector<int> dp(amount + 1, amount+1);
        dp[0] = 0;
        // find the minimum number to get 1 to amount
        for (int i = 1; i <= amount; i++)
            for (int coin : coins) // try each coin
                if (coin <= i) // coin should be less than or equal to amount
                    dp[i] = min(dp[i], dp[i-coin]+1); // find more optimal solution, 
                // dp[i-coin] -> previous subproblem, one is added since we use another coin
        
        // if there's no answer, dp[amount] is still -1 
        return dp[amount] > amount ? -1 : dp[amount];
 }                  
};
