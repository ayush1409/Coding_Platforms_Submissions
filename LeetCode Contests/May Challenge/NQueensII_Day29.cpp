class Solution {
public:
    void solveNQueensHelper(vector<vector<bool>> &board, int row, vector<bool> &cols, vector<bool> &lDiag, vector<bool> &rDiag, int &result){
        
        // found a valid combination
        if(row == cols.size()){
            result++ ;
            return ;
        }
        
        for(int col = 0 ; col < cols.size() ; col++){
            if(cols[col] == false && lDiag[row + col] == false && rDiag[row - col + cols.size() -1] == false){
                board[row][col] = true;
                cols[col] = true ;
                lDiag[row + col] = true ;
                rDiag[row - col + cols.size()-1] = true ;
                solveNQueensHelper(board, row+1, cols, lDiag, rDiag, result) ;
                board[row][col] = false ;
                cols[col] = false ;
                lDiag[row + col] = false ;
                rDiag[row - col + cols.size()-1] = false ;
            }
        }
    }
    int totalNQueens(int n) {
        vector<bool> cols(n, false) ;
        vector<bool> lDiag(2*n-1, false) ;
        vector<bool> rDiag(2*n-1, false) ;
        vector<vector<bool>> board(n, vector<bool>(n, false)) ;
        int result = 0 ;
        
        solveNQueensHelper(board, 0, cols, lDiag, rDiag, result) ;
        
        return result ;
    }
};