class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !vis[newRow][newCol] && grid[newRow][newCol] == 1){
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }

        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};