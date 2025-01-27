class Solution {
public:
    int f(int index, int buy, vector<int>& prices, int n, vector<vector<int>> &dp, int fee){
        // int profit = 0;

        if(index == n) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];

        if(buy){
            return dp[index][buy] = max((-prices[index] - fee + f(index+1, 0, prices, n, dp, fee)), (0 + f(index+1, 1, prices, n, dp, fee)));
        }

        return dp[index][buy] = max((prices[index] + f(index+1, 1, prices, n, dp, fee)), (0 + f(index+1, 0, prices, n, dp, fee)));
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, n, dp, fee);
    }
};