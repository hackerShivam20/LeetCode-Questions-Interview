class Solution {
// private:
//     int sum(int index, int n, int k, vector<int> &arr, vector<int> &dp){
//         if(index == n) return 0;

//         if(dp[index] != -1) return dp[index];

//         int maxi = INT_MIN;
//         int maxSum = INT_MIN;
//         int len = 0;

//         for(int i=index;i<min(n, index + k);i++){
//             len++;
//             maxi = max(maxi, arr[i]);
//             int Sum = len * maxi + sum(i+1, n, k, arr, dp);
//             maxSum = max(maxSum, Sum);
//         }
//         return dp[index] = maxSum;
//     }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        int prev = 0;

        for(int index=n-1;index>=0;index--){
            int maxi = INT_MIN;
            int maxSum = INT_MIN;
            int len = 0;

            for(int i=index;i<min(n, index + k);i++){
                len++;
                maxi = max(maxi, arr[i]);
                int Sum = len * maxi + dp[i+1];
                maxSum = max(maxSum, Sum);
            }
            dp[index] = maxSum;
        }

        return dp[0];
    }
};