class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size(); // original array size
        // insert 1 to both ends 
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        
        for (int len = 1; len <= n; ++len)
            for (int left = 1; left <= n - len + 1; ++left) 
            {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k) // k = index of balls to burst the last so left & right only left
                    dp[left][right] = max(dp[left][right], nums[left-1]*nums[k]*nums[right+1] + dp[left][k-1] + dp[k+1][right]);
            }
        return dp[1][n];
    }
};
