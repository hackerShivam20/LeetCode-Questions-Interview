class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> valid(n, false);

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int left = max(0, i - k);
                int right = min(n - 1, i + k);
                for (int j = left; j <= right; j++) {
                    valid[j] = true;
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (valid[i]) result.push_back(i);
        }

        return result;
    }
};
