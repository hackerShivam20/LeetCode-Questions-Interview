class Solution {
public:
    int numIslands(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }


        int rows = grid.size();
        int columns = grid[0].size();
        int islands = 0;

        vector<vector<bool>> vis(rows, vector<bool>(columns));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {  // Use integer 1 instead of character '1'
                    islands++;
                    traverseIsland(grid, i, j, vis);
                }
            }
        }
        return islands;  
    }

    void traverseIsland(vector<vector<int>>& grid, int row, int column, vector<vector<bool>> &vis) {
        if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() || vis[row][column] || grid[row][column] == 0) {
            return;
        }

        vis[row][column] = true;  // Set the land to 0 to mark it as visited

        traverseIsland(grid, row, column + 1, vis); // right cell
        traverseIsland(grid, row, column - 1, vis); // left cell
        traverseIsland(grid, row + 1, column, vis); // bottom cell
        traverseIsland(grid, row - 1, column, vis); // top cell
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (numIslands(grid) == 0 || numIslands(grid) > 1) return 0;
        else{
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1) {
                        grid[i][j] = 0;
                        if (numIslands(grid) != 1) {
                            return 1;
                        }
                        grid[i][j] = 1;  // Reset the cell to its original value
                    }
                }
            }
        }
        return 2;
    }
};
