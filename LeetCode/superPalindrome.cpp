// Problem : https://leetcode.com/problems/super-palindromes/

class Solution {
public:
    bool isPalindrome(string s){
        for(int i = 0, j = s.size()-1 ; i < s.size(), j >= 0 ; i++, j--){
            if(s[i] != s[j])
                return false ;
        }
        return true ;
    }
    int superpalindromesInRange(string left, string right){
        
        vector<unsigned long long int > palindromes ;
        unsigned int count = 0 ;
        unsigned long long int Left = stoll(left);
        unsigned long long int Right = stoll(right);
        
        for(int i = 1 ; i < 10 ; i++)
            palindromes.push_back(i) ;
        
        for(unsigned long long int i = 1 ; i < 10000 ; i++){
            string leftPart = to_string(i) ;
            string rightPart = string(leftPart.rbegin(), leftPart.rend()) ;
            
            palindromes.push_back(stoll(leftPart + rightPart)) ;
            
            for(int k = 0 ; k < 10 ; k++)
                palindromes.push_back(stoll(leftPart + to_string(k) + rightPart)) ;
            
        }
        
        //cout<<"List of palindromes : " ;
        for(unsigned long long int x : palindromes){
            unsigned long long int curr = x * x ;
            //cout<<x<<endl ;
            if(curr >= Left && curr <= Right && isPalindrome(to_string(curr)))
                count++ ;
        }
        
        return count ;
    }

};