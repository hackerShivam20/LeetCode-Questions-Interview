class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        for(int i = 0;i<=m;i++){
            dp[i][0] = 0;
        }
        for(int j = 0;j<=n;j++){
            dp[0][j] = 0;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else{ dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);}
            }
        }
        
        int length = dp[m][n];
        int index = length-1;
        int i = m, j = n;
        string s = "";

        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                s += str1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                s += str1[i-1];
                i--;
            }
            else{
                s += str2[j-1];
                j--;
            }
        }

        while(i>0){
            s += str1[i-1];
            i--;
        }

        while(j>0){
            s += str2[j-1];
            j--;
        }
        reverse(s.begin(),s.end());

        return s;
    }
};