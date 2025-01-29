class Solution {
public:
    bool compare(string& s1, string& s2){
        if(s1.size() != s2.size() + 1) return false;
        
        int first = 0;
        int second = 0;
        
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first ++;
                second ++;
            }
            else first ++;
        }
        if(first == s1.size() && second == s2.size()) return true;
        else return false; 
    }

    // bool comp(string& s1, string& s2){
    //     return s1.size() < s2.size();
    // }

    int longestStrChain(vector<string>& nums){
        int n = nums.size();
        vector<int> dp(n, 1);
    sort(nums.begin(), nums.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
        
        for(int i = 0;i<n;i++){
            for(int prev = 0;prev < i;prev++){
                if(compare(nums[i], nums[prev]) && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                }
            }
        }
        
        int element = -1;
        
        for(int i=0;i<n;i++){
            if(element < dp[i]){
                element = dp[i];
            }
        }
        return element;
    }
};