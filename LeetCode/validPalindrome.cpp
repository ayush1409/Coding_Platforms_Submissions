// Problem : https://leetcode.com/problems/valid-palindrome/
#include <cctype>

bool isPalindrome(string s) {
        
        if(s.empty())
            return true ;
        
        // remove all the spaces
        s.erase(remove(s.begin(), s.end(), ' '), s.end()) ;
        
        if(s.empty())
            return true ;
        
        unsigned int i = 0, j = s.size()-1 ;
        
        while(i < j){
            
            if(!isalnum(s[i])){		// position of first alphanumeric from left
                i++ ;
                continue ;
            }
            
            if(!isalnum(s[j])){		// position of first alphanumeric from right
                j-- ;
                continue ;
            }
            
            if(tolower(s[i]) != tolower(s[j]))
                return false ;
            i++ ;
            j-- ;
        }
        
        return true ;
}
