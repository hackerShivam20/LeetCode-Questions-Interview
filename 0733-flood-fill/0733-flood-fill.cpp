class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> dup = image;
        queue<pair<int,int>> q;

        int ic = image[sr][sc];
        q.push({sr,sc});
        dup[sr][sc] = color;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && dup[newRow][newCol] != color && image[newRow][newCol] == ic){
                    dup[newRow][newCol] = color;
                    q.push({newRow,newCol});
                }
            }
        }
        return dup;
    }
};