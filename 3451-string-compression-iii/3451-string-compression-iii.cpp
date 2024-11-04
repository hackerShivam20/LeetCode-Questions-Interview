class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        std::string ans = "";
        
        int i = 0;
        while (i < n) {
            char currentChar = word[i];
            int count = 0;

            // Count occurrences of currentChar, limiting to a maximum of 9
            while (i < n && word[i] == currentChar && count < 9) {
                count++;
                i++;
            }

            // Append the count and the character to the result
            ans += std::to_string(count) + currentChar;
        }
        
        return ans;
    }
};