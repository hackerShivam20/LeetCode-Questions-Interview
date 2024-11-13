class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n - 1; ++i) {
            // Finding the range of indices for fair pairs
            int start = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int end = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;
            if (start <= end) {
                count += end - start + 1;
            }
        }

        return count;
    }
};