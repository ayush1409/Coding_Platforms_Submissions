class Solution {
public:
    int min(int a, int b, int c){
        if(a < b){
            if(a < c)
                return a ;
            else return c ;
        }
        if(b < c)
            return b ;
        else return c ;
        
    }
    int minDistance(string word1, string word2) {
        int distance[word1.length() + 1][word2.length() + 1] ;
        
        distance[0][0] = 0 ;
        
        for(int i = 1 ; i <= word1.length() ; i++){
            distance[i][0] = i ;
        }
        
        for(int i = 1 ; i <= word2.length() ; i++){
            distance[0][i] = i ;
        }
        
        for(int i = 1 ; i <= word1.length() ; i++){
            for(int j = 1 ; j <= word2.length() ; j++){
                if(word1[i-1] == word2[j-1])
                    distance[i][j] = distance[i-1][j-1] ;
                else
                    distance[i][j] = 1 + min(distance[i-1][j], distance[i][j-1], distance[i-1][j-1]) ;
            }
        }
                
        return distance[word1.length()][word2.length()] ;
    }
};
