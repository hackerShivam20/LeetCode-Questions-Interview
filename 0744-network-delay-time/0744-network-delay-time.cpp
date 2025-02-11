#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1); // Corrected initialization

        for(auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n + 1, 1e9);

        pq.push({0, k});
        dis[k] = 0;

        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adjDist = it.second;

                if(dist + adjDist < dis[adjNode]) {
                    dis[adjNode] = dist + adjDist;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }

        int ans = -1;
        for(int i = 1; i <= n; i++) {
            if(dis[i] == 1e9) return -1;
            ans = max(ans, dis[i]); // Corrected max function usage
        }
        return ans;
    }
};
