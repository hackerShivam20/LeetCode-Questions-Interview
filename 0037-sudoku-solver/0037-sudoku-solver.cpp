class Solution {
public:

    bool isvalid(vector<vector<char>>& board, char c, int row, int col, int m, int n){
        for(int i=0;i<9;i++){
            if(board[row][i] == c){
                return false;
            }

            if(board[i][col] == c){
                return false;
            }

            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == c){
                return false;
            }
        }
        return true;
    }

    bool solvesudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(board, c, i, j, m, n)){
                            board[i][j] = c;
        
                            if(solvesudoku(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board){
        solvesudoku(board);
    }
};