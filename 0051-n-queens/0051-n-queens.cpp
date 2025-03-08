class Solution {
public:

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> &leftrow, vector<int> &upperleft, vector<int> &lowerleft){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(leftrow[row] == 0 && upperleft[row + col] == 0 && lowerleft[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upperleft[row + col] = 1;
                lowerleft[n - 1 + col - row] = 1;
                solve(col + 1, board, ans, n, leftrow, upperleft, lowerleft);
                board[row][col] = '.';
                leftrow[row] = 0;
                upperleft[row + col] = 0;
                lowerleft[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        vector<int> leftrow(n, 0), upperleft(2*n-1, 0), lowerleft(2*n-1, 0);
        solve(0, board, ans, n, leftrow, upperleft, lowerleft);
        return ans;
    }
};