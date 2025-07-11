class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> targetCount;
        for (char c : t) targetCount[c]++;

        int required = targetCount.size();
        int formed = 0;
        unordered_map<char, int> windowCount;

        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;

        while (right < s.length()) {
            char c = s[right];
            windowCount[c]++;

            if (targetCount.count(c) && windowCount[c] == targetCount[c])
                formed++;

            while (formed == required) {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char lc = s[left];
                windowCount[lc]--;
                if (targetCount.count(lc) && windowCount[lc] < targetCount[lc])
                    formed--;

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};