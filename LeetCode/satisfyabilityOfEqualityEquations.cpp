// Problem: https://leetcode.com/problems/satisfiability-of-equality-equations/

class Solution {
public:
    struct Node{
        int parent = -1 ;
        int rank = 0 ;
    } ;
    
    int findP(int v, vector<Node> &parent){
        if(parent[v].parent == -1)
            return v ;
        parent[v].parent = findP(parent[v].parent, parent) ;
        return parent[v].parent ;
    }
    
    void merge(int u, int v, vector<Node> &parent){
        int uP = findP(u, parent) ;
        int vP = findP(v, parent) ;
        
        if(parent[uP].rank < parent[vP].rank){
            parent[uP].parent = vP ;
        }
        else if(parent[vP].rank > parent[vP].rank){
            parent[vP].parent = uP ;
        }
        else{
            parent[vP].parent = uP ;
            parent[uP].rank += 1 ;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<Node> parent(26) ;
        int u,v,uP,vP ;
        
        vector<string> contradictions ;
        
        for(auto equation: equations){
            u = equation[0] - 'a' ;
            v = equation[3] - 'a' ;
            uP = findP(u, parent) ;
            vP = findP(v, parent) ;
           
            if(equation[1] == '!')
                contradictions.push_back(equation) ;
            
            if(uP != vP && equation[1] == '=')
                merge(uP, vP, parent) ;
        }
        
        for(auto equation: contradictions){
            u = equation[0] - 'a' ;
            v = equation[3] - 'a' ;
            uP = findP(u, parent) ;
            vP = findP(v, parent) ;
            
            if(uP == vP)
                return false ;
        }
        
        return true ;
    }
};