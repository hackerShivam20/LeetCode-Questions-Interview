class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int time1 = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            time1 = max(time1,time);
            q.pop();

            for(int i=0;i<4;i++){
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && grid[newRow][newCol] == 1 && vis[newRow][newCol] != 2){
                    q.push({{newRow,newCol},time + 1});
                    vis[newRow][newCol] = 2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time1;
    }
};