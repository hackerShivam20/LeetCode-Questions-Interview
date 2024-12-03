class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int i = 0, k = 0; // `i` tracks the current index in `s`, `k` tracks the space indices
        int n1 = spaces.size();
        string ans = "";

        while (i < n) {
            // Check if the current index matches a space position
            if (k < n1 && i == spaces[k]) {
                ans += ' '; // Add a space
                k++;        // Move to the next space index
            }
            // Append the current character from `s`
            ans += s[i];
            i++;
        }
        return ans;
    }
};