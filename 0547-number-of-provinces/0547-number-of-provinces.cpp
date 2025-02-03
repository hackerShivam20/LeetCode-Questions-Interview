class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int> adjList[]){
        vis[node] = 1;

        for(auto i : adjList[node]){
            if(!vis[i]){
                dfs(i, vis, adjList);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjList[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adjList);
            }
        }
        return cnt;
    }
};