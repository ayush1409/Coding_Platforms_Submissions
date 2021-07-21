// Problem: https://leetcode.com/problems/word-search/
class Solution {
public:
    
    bool search(vector<vector<char>> &board, int i, int j, int k, string word){
        int m = board.size() ;
        int n = board[0].size() ;

        if(k == word.size())
            return true ;
        
        if(i < 0 || i >= m || j < 0 || j >= n || word[k] != board[i][j])
            return false ;
        
        char temp = board[i][j] ;
        board[i][j] = '#' ;
        bool result = search(board, i-1, j, k+1, word) || search(board, i+1, j, k+1, word) ||
                        search(board, i, j-1, k+1, word) || search(board, i, j+1, k+1, word) ;
        board[i][j] = temp ;
        
        return result ;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size() ;
        int n = board[0].size() ;   
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0] && search(board, i, j, 0, word)) 
                    return true ;
            }
        }
        
        return false ;
    }
};

