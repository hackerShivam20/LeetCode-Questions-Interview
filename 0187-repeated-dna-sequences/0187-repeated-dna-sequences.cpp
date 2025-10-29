class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();

        if(n <= 10) return {};

        unordered_set<string> seen;
        unordered_set<string> repeated;

        for(int i=0;i<=n-10;i++){
            string st = s.substr(i, 10);
            if(seen.count(st)){
                repeated.insert(st);
            }
            else{
                seen.insert(st);
            }
        }
        return vector<string>(repeated.begin(), repeated.end());
    }
};