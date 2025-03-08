class Solution{
private:
    bool isPalindrome(int i, int j, string &s){
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

private:
    int pp(int index, int n, string &s, vector<int> &dp){
        if(index == n) return 0;
        int totalCuts = INT_MAX;

        if(dp[index] != -1) return dp[index];

        for(int j = index;j<n;j++){
            if(isPalindrome(index, j, s)){
                int cost = 1 + pp(j+1, n, s, dp);
                totalCuts = min(totalCuts, cost);
            }
        }
        return dp[index] = totalCuts;
    }
public:
    int minCut(string s) {
        int n = s.length();
        if(n == 1) return 0;
        vector<int> dp(n+1, 0);

        for(int index = n-1;index>=0;index--){
            int totalCuts = INT_MAX;

            for(int j = index;j<n;j++){
                if(isPalindrome(index, j, s)){
                    int cost = 1 + dp[j+1];
                    totalCuts = min(totalCuts, cost);
                }
            }
            dp[index] = totalCuts;
        }
        return dp[0]-1;
    }
};