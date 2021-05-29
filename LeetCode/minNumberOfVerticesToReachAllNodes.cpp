// Problem: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> inDeg(n, 0) ;
        vector<int> result ;
        
        for(auto edge : edges){
            inDeg[edge[1]]++ ;
        }
        
        for(int i = 0 ; i < n ; i++)
            if(inDeg[i] == 0)
                result.push_back(i) ;
        
        return result ;
        
    }
};