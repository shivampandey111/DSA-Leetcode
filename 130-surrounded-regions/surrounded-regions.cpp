class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool valid(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& board, int n, int m, int i, int j){
        board[i][j] = '#';
        for(int k = 0; k<4; k++){
            int row = x[k] + i;
            int col = y[k] + j;
            if(valid(row, col, n, m) && board[row][col]=='O'){
                dfs(board, n, m, row, col);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        bool res = true;
        int n = board.size();
        int m = board[0].size();
        for(int j = 0; j<m; j++){
            if(board[0][j]=='O'){
                dfs(board, n, m, 0, j);
            }
        }
        for(int j = 0; j<m; j++){
            if(board[n-1][j]=='O'){
                dfs(board, n, m, n-1, j);
            }
        }
        for(int i = 0; i<n; i++){
            if(board[i][0]=='O'){
                dfs(board, n, m, i, 0);
            }
        }
        for(int i = 0; i<n; i++){
            if(board[i][m-1]=='O'){
                dfs(board, n, m, i, m-1);
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};