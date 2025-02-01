class Solution {
public:
    int minimumCostToCut(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxCoins = INT_MIN;

        for(int k=i;k<=j;k++){
            int cost = arr[i-1] * arr[k] * arr[j+1]; 
            int otherCost = minimumCostToCut(i, k-1, arr, dp) + minimumCostToCut(k+1, j, arr, dp);
            maxCoins = max(maxCoins, cost + otherCost);
        }
        return dp[i][j] = maxCoins;
    }
    int maxCoins(vector<int>& nums){
        int n1 = nums.size();
        vector<vector<int>> dp(n1+2, vector<int>(n1+2, 0));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        for(int i=n1;i>=1;i--){
            for(int j=i;j<=n1;j++){
                int maxCoins = INT_MIN;

            for(int k=i;k<=j;k++){
                int cost = nums[i-1] * nums[k] * nums[j+1]; 
                int otherCost = dp[i][k-1] + dp[k+1][j];
                maxCoins = max(maxCoins, cost + otherCost);
            }
            dp[i][j] = maxCoins;
            }
        }
        return dp[1][n1];
    }
};