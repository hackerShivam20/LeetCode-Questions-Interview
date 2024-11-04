class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        vector<char> ans;
        int i=0;

        while(i<n){
            char c = chars[i];
            int cnt = 0;

            while(i<n && c == chars[i]){
                cnt++;
                i++;
            }
            if(cnt == 1) ans.push_back(c);
            else if(cnt < 10){
                ans.push_back(c);
                ans.push_back(cnt + '0');
            }
            else{
                string s = to_string(cnt);
                ans.push_back(c);
                for(auto chh:s){
                    ans.push_back(chh);
                }
            }
        }
        chars = ans;
        return chars.size();
    }
};