class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0; 
        for (const int & price : prices)
        {
            // keep track of minimum price comparing current price and previous min price
            minPrice = min (minPrice, price);
            // profit = price - minPrice vs previous maxProfit
            maxProfit = max (maxProfit, price-minPrice);
        }
        return maxProfit;
    }
};
