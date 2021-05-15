class Solution {
public:
    void swap(char &ch1, char &ch2){
        char temp = ch1 ;
        ch1 = ch2 ;
        ch2 = temp ;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size() ;
        int n = box[0].size() ;
        
        vector<vector<char>> result(n, vector<char>(m, '.')) ;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++)
                result[j][i] = box[i][j] ;
        }
        
        for(int k = 0 ; k < m ; k++){
            int i;
            for(i = n ; i > 0 ; i--){
                if(result[i-1][k] == '.')
                    break ;
            }
            if(i == 1)
                continue ;
            
            for(int j = n-1 ; j >= 0 ; j--){
                if(result[j][k] == '#' && i >= 1){
                    i-- ;
                    swap(result[j][k], result[i][k]) ;
                }
                for(int nextI = i; nextI > 0 ; nextI--){
                    if(result[nextI-1][k] == '.'){
                        i = nextI ;
                        break ;
                    }
                }
                
                if(i == 1)
                    break ;
                
                if(result[j][k] == '*' && j >= 1 && result[j-1][k] == '.')
                    i = j ;
            }
            
            
        }
        
        
        if(m == 1)
            reverse(result.begin(), result.end()) ;
        for(int i = 0 ; i < n ; i++)
                reverse(result[i].begin(), result[i].end()) ;
        
        return result ;
    }
};