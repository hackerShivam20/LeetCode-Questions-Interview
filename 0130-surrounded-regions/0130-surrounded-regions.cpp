class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, int dx[], int dy[], vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        vis[row][col] = 1;
        for(int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
            && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, dx, dy, board); 
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, vis, dx, dy, board);
            }
            if(board[i][n-1] == 'O' && !vis[i][n-1]){
                dfs(i, n-1, vis, dx, dy, board);
            }
        }

        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(0, j, vis, dx, dy, board);
            }
            if(board[m-1][j] == 'O' && !vis[m-1][j]){
                dfs(m-1, j, vis, dx, dy, board);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};