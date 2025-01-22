class Solution {
public:

    const int prime = 1e9 + 7;
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s[i] == t[j]) ans = solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
        else ans = solve(i-1, j, s, t, dp);
        dp[i][j] = ans;
        return ans;
    }

    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=m;i++){
            dp[0][i] = 0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ans = 0;
                if(s[i-1] == t[j-1]) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % prime;
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};