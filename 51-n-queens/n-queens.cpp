class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n) {

     
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nQueens(vector<string>& board, int row, int n,
                 vector<vector<string>>& ans) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                board[row][col] = 'Q';

                nQueens(board, row + 1, n, ans);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        nQueens(board, 0, n, ans);

        return ans;
    }
};



// class Solution {
// public:
//     void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftrow,vector<int> &upperdiagonal,vector<int> &lowerdiagonal, int n){
//         if(col==n){
//             ans.push_back(board);
//             return;
//         }
//         for(int row=0;row<n;row++){
//             if(leftrow[row]==0 && upperdiagonal[(n-1)+col-row]==0 && lowerdiagonal[(row+col)]==0){
//                 board[row][col]='Q';
//                 leftrow[row]=1;
//                 upperdiagonal[(n-1)+col-row]=1;
//                 lowerdiagonal[(row+col)]=1;
//                 solve(col+1,board,ans,leftrow,upperdiagonal,lowerdiagonal,n);
//                 board[row][col]='.';
//                 leftrow[row]=0;
//                 upperdiagonal[(n-1)+col-row]=0;
//                 lowerdiagonal[(row+col)]=0;
//             }
//         }


//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n,'.');
//         for(int i=0;i<n;i++){
//             board[i]=s; 
//         }
//         vector<int> leftrow(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
//         solve(0,board,ans,leftrow,upperdiagonal,lowerdiagonal,n);
//         return ans;
//     }
// };