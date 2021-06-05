// Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    
    // Time: O(4^(n*n)), Space : O(n)
    map<int, vector<char>> digitMap ;
    
    void createMap(){
        digitMap.insert({1, vector<char>()}) ;
        for(int i = 0, j = 2 ; i <= 25, j <= 9 ; j++){
            digitMap[j].push_back('a' + i++) ;
            digitMap[j].push_back('a' + i++) ;
            digitMap[j].push_back('a' + i++) ;
            if(j == 7 || j == 9)
                digitMap[j].push_back('a' + i++) ;
        }
    }
    
    void letterHelper(int i, string digits, string s, vector<string> &result){
        if(i == digits.size()){
            result.push_back(s) ;
            return ;
        }
        
        int num = digits[i] - '0' ;
        
        for(auto x : digitMap[num]){
            s.push_back(x) ;
            letterHelper(i+1, digits, s, result) ;
            s.pop_back() ;
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>() ;
        
        vector<string> result ;
        string s ;
        
        createMap() ;    
        
        letterHelper(0, digits, s, result) ;
        
        return result ;
    }
};