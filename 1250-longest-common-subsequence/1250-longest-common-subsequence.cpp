class Solution {
public:
    // int solve(int ind1, int ind2, string text1, string text2, vector<vector<int>> &dp){
    //     if(ind1 == 0 || ind2 == 0) return 0;
    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    //     if(text1[ind1-1] == text2[ind2-1]) return dp[ind1][ind2] = 1 + solve(ind1-1, ind2-1, text1, text2, dp);
    //     return dp[ind1][ind2] = max (solve(ind1, ind2-1, text1, text2, dp), solve(ind1-1, ind2, text1, text2, dp));
    // }

    int longestCommonSubsequence(string text1, string text2){
        int n = text1.length(), m = text2.length();
        vector<int> prev(m+1, 0), temp(m+1, 0);

        for(int i=0;i<=n;i++){
            prev[0] = 0;
        }
        for(int i=0;i<=m;i++){
            prev[i] = 0;
        }

        for(int ind1 = 1;ind1<=n;ind1++){
            for(int ind2 = 1;ind2<=m;ind2++){
                if(text1[ind1-1] == text2[ind2-1]) temp[ind2] = 1 + prev[ind2-1];
                else temp[ind2] = max(temp[ind2-1], prev[ind2]);
            }
            prev = temp;
        }
        return prev[m];
    }
};