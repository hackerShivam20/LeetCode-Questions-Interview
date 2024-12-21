class Solution {
public:
    int dfs(vector<vector<int>> &adj, vector<int> &values, int& k, int &cnt, int curr, int parent = -1){
        int sum = values[curr];

        for(int nbr : adj[curr]){
            if(nbr != parent){
                sum += dfs(adj, values, k, cnt, nbr, curr);
            }
        }
        sum %= k;
        if(sum == 0) cnt++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        int cnt = 0;

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(adj, values, k, cnt, 0);
        return cnt;
    }
};