class Solution {
public:
    // int f(int index, int buy, vector<int>& prices, int n, int capacity, vector<vector<vector<int>>> &dp){
    //     // int profit = 0;

    //     if(index == n || capacity == 0) return 0;
    //     if(dp[index][buy][capacity] != -1) return dp[index][buy][capacity];

    //     if(buy){
    //         return dp[index][buy][capacity] = max((-prices[index] + f(index+1, 0, prices, n, capacity, dp)), (0 + f(index+1, 1, prices, n, capacity, dp)));
    //     }

    //     return dp[index][buy][capacity] =  max((prices[index] + f(index+1, 1, prices, n, capacity-1, dp)), (0 + f(index+1, 0, prices, n, capacity, dp)));
    // }

    int maxProfit(vector<int>& prices){
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int index=n-1;index >= 0 ;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int capacity=1;capacity<=2;capacity++){
                    if(buy){
                        curr[buy][capacity] = max((-prices[index] + ahead[0][capacity]), (ahead[1][capacity]));
                    }
                    else{
                        curr[buy][capacity] =  max((prices[index] + ahead[1][capacity-1]), (0 + ahead[0][capacity]));
                    }
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size(), buy1=INT_MAX, buy2=INT_MAX, tr1=0, tr2=0;
//         for (int i = 0; i < n; i++) {
//             buy1=min(buy1, prices[i]); //buying price 1
//             tr1=max(tr1, prices[i]-buy1);
//             buy2=min(buy2, prices[i]-tr1); //buying price 2
//             tr2=max(tr2, prices[i]-buy2);
//         }
//         return tr2;
//     }
// };