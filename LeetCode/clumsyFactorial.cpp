// Problem : https://leetcode.com/problems/clumsy-factorial/

class Solution {
public:
    int clumsy(int N) {
        int op = 0 ;        // {*,/,+,-}
        int result ;
        vector<int> vec ;
        
        // High Priority operations
        while(N >= 1){
            if(op == 0){
                if(N == 1){
                    vec.push_back(1) ;
                    break ;
                }
                
                if(N == 2){
                    vec.push_back(2) ;
                    break ;
                }
            
                vec.push_back(N * (N-1) / (N-2)) ;
                N = N-2 ;  
                op = (op + 2) % 4 ;
            }
            else if(op == 2){
                N = N - 1 ;
                
                if(N == 1){
                    vec.push_back(1) ;
                    break ;
                }
                
                vec.push_back(N) ;
                op = (op + 1) % 4 ;
            }
            else{
                if(N == 1){
                    vec.push_back(1) ;
                    break ;
                }
                N = N-1 ;
                op = (op + 1) % 4 ;
            } 
        }
        
        result = vec[0] ;
        // Low Priority Operations
        for(int i = 1 ; i < vec.size() ; i++){
            if(i % 2 != 0)
                result += vec[i] ;
            else
                result -= vec[i] ;
        }
        
        return result ;
    }
};