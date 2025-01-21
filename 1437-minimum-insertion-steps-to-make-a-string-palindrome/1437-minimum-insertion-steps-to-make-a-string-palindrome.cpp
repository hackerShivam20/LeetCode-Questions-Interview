class Solution {
public:
    int longestCommonSubsequence(string text1, string text2){
        int m = text1.length();
        int n = text2.length();
        // vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1]) curr[j] = 1 + prev[j-1];
                else{ curr[j] = 0 + max(prev[j], curr[j-1]);}
            }
            prev=curr;
        }
        return prev[n];
    }

    int minInsertions(string s){
        string t = s;
        reverse(t.begin(),t.end());
        return s.length() - longestCommonSubsequence(s,t);
    }
};