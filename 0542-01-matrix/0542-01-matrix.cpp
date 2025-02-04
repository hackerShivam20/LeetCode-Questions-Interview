class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int  m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> distance(m, vector<int>(n,0));
        vector<vector<int>> vis(m, vector<int>(n,0));

        queue<pair<pair<int,int>, int>> q;
        // int steps = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            distance[row][col] = dis;

            for(int i=0;i<4;i++){
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && vis[newRow][newCol] != 1 && mat[newRow][newCol] == 1){
                    q.push({{newRow, newCol}, dis+1});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return distance;
    }
};