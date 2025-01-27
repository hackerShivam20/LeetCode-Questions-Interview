class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> ahead(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        for(int index=n-1;index >= 0 ;index--){
            for(int buy = 0;buy<=1;buy++){
                for(int capacity=1;capacity<=k;capacity++){
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
        return ahead[1][k];
    }
};