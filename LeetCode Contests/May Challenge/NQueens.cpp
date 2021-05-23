/*
    Problem : The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
    Given an integer n, return all distinct solutions to the n-queens puzzle.
    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

    Example 1:
    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

    Example 2:
    Input: n = 1
    Output: [["Q"]]
    
    Constraints:
    1 <= n <= 9
*/

class Solution {
public:
    void solveNQueensHelper(vector<vector<bool>> &board, int row, vector<bool> &cols, vector<bool> &lDiag, vector<bool> &rDiag, vector<vector<string>> &result){
        
        // found a valid combination
        if(row == cols.size()){
        
            vector<string> combination(cols.size()) ;
            
            for(int i = 0 ; i < cols.size() ; i++){
                for(int j = 0 ; j < cols.size() ; j++){
                    if(board[i][j])
                        combination[i] += 'Q' ;
                    else
                        combination[i] += '.' ;
                }
            }
            
            result.push_back(combination) ;
            
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
    
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> cols(n, false) ;
        vector<bool> lDiag(2*n-1, false) ;
        vector<bool> rDiag(2*n-1, false) ;
        vector<vector<bool>> board(n, vector<bool>(n, false)) ;
        vector<vector<string>> result ;
        
        solveNQueensHelper(board, 0, cols, lDiag, rDiag, result) ;
        
        return result ;
    }
};