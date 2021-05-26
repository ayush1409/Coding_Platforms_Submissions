// Problem : https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> inDeg(n+1, 0) ;
        vector<int> outDeg(n+1, 0) ;
        
        for(auto x: trust){
            inDeg[x[1]]++ ;
            outDeg[x[0]]++ ;
        }
        
        int judge = -1 ;
        for(int i = 1 ; i <= n ; i++){
            if(inDeg[i] == n-1 && outDeg[i] == 0)
                judge = i ;
        }
        
        return judge ;
    
        /*
        WRONG APPROACH
        vector<bool> isTownJudge(n+1, true) ;
        
        for(int i = 0 ; i < trust.size() ; i++){
            isTownJudge[trust[i][0]] = false ;
        }
        
        for(int i = 1 ; i <= n ; i++){
            if(isTownJudge[i])
                return i ;
        }
        
        return -1 ;
        */
    }
    
    
};