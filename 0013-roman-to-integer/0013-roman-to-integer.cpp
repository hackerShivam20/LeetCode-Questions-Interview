class Solution {
public:
    int romanToInt(string s){
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(roman[s[i]]<roman[s[i+1]]){
                //for cases such as IV,CM, XL, etc...
                ans=ans-roman[s[i]];
            }
            else{   
                int curr = roman[s[i]];
                ans += curr;
            }
        } 
        return ans;
    }
};