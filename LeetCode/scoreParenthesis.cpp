// Problem: https://leetcode.com/problems/score-of-parentheses/

class Solution {
public:
    
    int scoreHelper(int start, int end, vector<int> &mapping){
        if(start + 1 == end)
            return 1 ;
        
        int ans = 0 ; 
        
        for(int i = start+1 ; i < end ;){
            ans += scoreHelper(i, mapping[i], mapping) ;
            i = mapping[i] + 1 ;
        }
        
        return ans*2 ;
    }
    
    int scoreOfParentheses(string s) {
        s = "(" + s + ")" ;
        int n = s.size() ;
        vector<int> st, mapping(n) ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                st.push_back(i) ;
            }
            else{
                mapping[st.back()] = i ;
                mapping[i] = st.back() ;
                st.pop_back() ;
            }
        }
        return scoreHelper(0, n-1, mapping)/2 ;
    }
};