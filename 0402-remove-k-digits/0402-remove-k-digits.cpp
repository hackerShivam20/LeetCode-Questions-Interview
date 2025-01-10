class Solution {
public:
    string removeKdigits(string num, int k){
        int n = num.length();
        stack<char> s;
        if(n == k) return "0";

        for(int i=0;i<n;i++){
            while(!s.empty() && k>0 && (s.top() - '0') > (num[i] - '0')){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k>0){
            s.pop();
            k--;
        }
        string ans = "";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        while(!ans.empty() && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        if(ans.length() == 0) return "0";
        return ans;
    }
};