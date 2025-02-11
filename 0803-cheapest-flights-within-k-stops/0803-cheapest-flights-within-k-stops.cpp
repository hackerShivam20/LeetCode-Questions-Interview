class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];

        for(auto it:flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dis(n, 1e9);
        // ({steps, {node, dis}})
        queue<pair<int, pair<int, int>>> q;

        dis[src] = 0;
        q.push({0, {src, 0}});

        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();

            for(auto it:adj[node]){
                int adjNode = it.first;
                int adjDist = it.second;

                if(steps > k) continue;

                if(dist + adjDist < dis[adjNode] && steps <= k){
                    dis[adjNode] = dist + adjDist;
                    q.push({steps + 1, {adjNode, dist + adjDist}});
                }
            }
        }
        if(dis[dst] == 1e9) return -1;
        return dis[dst];
    }
};