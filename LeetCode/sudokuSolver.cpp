// problem: https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    /*
    void displayBoard(vector<vector<char>> &board){
        int n = board.size() ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++)
                cout<<board[i][j]<<" " ;
            cout<<endl ;
        }
    }
    */
    bool isValid(vector<vector<char>> &board, int i, int j, char option){
        int n = board.size();
        
        // checking inside 3*3 box
        int x = i - i%3 ;
        int y = j - j%3 ;
        
        for(int p = 0 ; p < 3 ; p++){
            for(int q = 0 ; q < 3 ; q++)
                if(board[p+x][q+y] == option)
                    return false ;
        }
        
        // checking row
        for(int k = 0 ; k < n ; k++){
            if(board[i][k] == option)
                return false ;
        }
        
        // checking column
        for(int k = 0 ; k < n ; k++){
            if(board[k][j] == option)
                return false ;
        }
        
        return true ;
    }
    
    bool solveSudokuHelper(vector<vector<char>> &board, int i, int j){
        int n = board.size() ;
        int nexti, nextj ;
        
        if(i == n){
            // displayBoard(board) ;
            return true ;
        }
        
        if(j == n){
            nexti = i+1 ;
            nextj = 0 ;
        }
        else{
            nexti = i ;
            nextj = j + 1 ;
        }
    
        if(board[i][j] != '.'){
            return solveSudokuHelper(board, nexti, nextj) ;
        }
        
        for(char option = '1' ; option <= '9' ; option++){
            if(isValid(board, i, j, option)){
                board[i][j] = option ;
                if(solveSudokuHelper(board, nexti, nextj)) 
                    return true ;
                else
                    board[i][j] = '.' ;
            }
        }
        
        return false ;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        solveSudokuHelper(board, 0, 0) ;
        
    }
};