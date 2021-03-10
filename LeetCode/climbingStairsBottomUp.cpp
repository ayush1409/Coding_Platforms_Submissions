// Problem : https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n+1) ;
        
        for(int i = 0 ; i < steps.size() ; i++){
            steps[i] = 0 ;
        }
        
        steps[0] = 1 ;
        
        for(int i = 0 ; i < steps.size() ; i++){
            if(i+1 < steps.size())
                steps[i+1] = steps[i+1] + steps[i] ;
            
            if(i+2 < steps.size())
                steps[i+2] = steps[i+2] + steps[i] ;
        }
        
        return steps[steps.size() - 1] ;
    }
};
