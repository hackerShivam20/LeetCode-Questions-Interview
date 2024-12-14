class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(n, false); // Use bool for visited instead of -1/-2
        long long score = 0;

        // Push all elements into the priority queue with their indices
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        // Process the priority queue
        while (!pq.empty()) {
            int ele = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            // If the current element is not marked
            if (!vis[ind]) {
                // Mark the current element and its adjacent elements
                vis[ind] = true;
                if (ind > 0) vis[ind - 1] = true; // Mark left neighbor
                if (ind < n - 1) vis[ind + 1] = true; // Mark right neighbor

                // Add the value to the score
                score += ele;
            }
        }

        return score;
    }
};