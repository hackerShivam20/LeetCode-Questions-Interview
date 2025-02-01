class Solution {
public:
    int minimumCostToCut(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for(int k=i;k<=j;k++){
            int cost = (arr[j+1] - arr[i-1]) + minimumCostToCut(i, k-1, arr, dp) + minimumCostToCut(k+1, j, arr, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts){
        int n1 = cuts.size();
        vector<vector<int>> dp(n1+2, vector<int>(n1+2, 0));
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        for(int i=n1;i>=1;i--){
            for(int j=i;j<=n1;j++){
                // if(i>j) continue;

                int mini = INT_MAX;

                for(int k=i;k<=j;k++){
                    int cost = (cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n1];
    }
};