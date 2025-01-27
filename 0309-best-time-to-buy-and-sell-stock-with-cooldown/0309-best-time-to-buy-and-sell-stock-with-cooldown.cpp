class Solution {
public:
    int f(int index, int buy, vector<int>& prices, int n, vector<vector<int>> &dp){
        // int profit = 0;

        if(index >= n) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];

        if(buy){
            return dp[index][buy] = max((-prices[index] + f(index+1, 0, prices, n, dp)), (0 + f(index+1, 1, prices, n, dp)));
        }

        return dp[index][buy] = max((prices[index] + f(index+2, 1, prices, n, dp)), (0 + f(index+1, 0, prices, n, dp)));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));
        // dp[n][0] = dp[n][1] = 0;

        for(int index = n-1;index>=0;index--){
            dp[index][1] = max((-prices[index] + dp[index+1][0]), (0 + dp[index+1][1]));
            dp[index][0] = max((prices[index] + dp[index+2][1]), (0 + dp[index+1][0]));
        }
        return dp[0][1];
    }
};