// Problem: https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    void generate(string s, int openCount, int closeCount, int n, vector<string> &result){
        
        if(s.size() == 2*n){
            result.push_back(s) ;
            return  ;
        }
        
        if(openCount < n){
            s += '(' ;
            generate(s, openCount+1, closeCount, n, result) ;
            s.pop_back() ;
        }
        if(openCount > closeCount && closeCount < n){
            s += ')' ;
            generate(s, openCount, closeCount+1, n, result) ;
            s.pop_back() ;
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result ;
        
        generate("", 0, 0, n, result) ;
        
        return result ;
    }
};