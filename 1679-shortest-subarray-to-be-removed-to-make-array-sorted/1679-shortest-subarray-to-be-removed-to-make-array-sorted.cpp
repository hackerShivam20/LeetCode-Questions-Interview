class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
    int left = 0, right = n - 1;

    // Find the longest non-decreasing subarray from the start
    while (left < n - 1 && arr[left] <= arr[left + 1]) {
        ++left;
    }
    
    // If the whole array is non-decreasing
    if (left == n - 1) {
        return 0;
    }

    // Find the longest non-decreasing subarray from the end
    while (right > 0 && arr[right - 1] <= arr[right]) {
        --right;
    }

    // Calculate minimum subarray to remove
    int result = min(n - left - 1, right); // remove either left or right part

    // Try to merge the left part with the right part
    int i = 0, j = right;
    while (i <= left && j < n) {
        if (arr[i] <= arr[j]) {
            result = min(result, j - i - 1);
            ++i;
        } else {
            ++j;
        }
    }

    return result;
    }
};