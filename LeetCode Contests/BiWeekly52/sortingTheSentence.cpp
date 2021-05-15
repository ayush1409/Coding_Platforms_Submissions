#include <string>
class Solution {
public:
    
    static bool stringCompare(string s1, string s2){
        int x = s1[s1.size()-1] - '0' ;
        int y = s2[s2.size()-1] - '0' ;
        
        return x < y ;
    }
    
    string sortSentence(string s) {
        vector<string> vec ;
        string temp ;
        string result ;
        
        for(int i = 0 ; i < s.size() ; i++){
            
            if(s[i] == ' '){
                vec.push_back(temp) ;
                temp = "" ;
                continue ;
            }
            
            temp += s[i] ;
            
            if(i == s.size()-1){
                vec.push_back(temp) ;
                continue ;
            }
        }
        
        sort(vec.begin(), vec.end() , stringCompare) ;
        
        for(int i = 0 ; i < vec.size() ; i++){
            vec[i].erase(vec[i].size()-1) ;
            result += vec[i] ;
            
            if(i != vec.size()-1)
                result += ' ' ;
        }
        
        return result ;
    }
};