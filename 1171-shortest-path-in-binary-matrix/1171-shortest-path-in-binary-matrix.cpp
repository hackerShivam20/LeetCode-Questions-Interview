class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){

        int V = grid.size();

        if (grid[0][0] != 0 || grid[V-1][V-1] != 0) return -1;
        if (V == 1) return 1;

        // {dist, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        vector<vector<int>> dis(V, vector<int> (V, 1e9));
        dis[0][0] = 1;

        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()){
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for(int i=0;i<8;i++){
                int nRow = row + dx[i];
                int nCol = col + dy[i];

                if(nRow >= 0 && nRow < V && nCol >= 0 && nCol < V && grid[nRow][nCol] == 0){
                    if(dist + 1 < dis[nRow][nCol]){
                        dis[nRow][nCol] = dist + 1;
                        if (nRow == V-1 &&
                        nCol == V-1)
                        return dist + 1;
                        q.push({dist + 1, {nRow, nCol}});
                    }
                }
            }
        }
        return -1;
    }
};