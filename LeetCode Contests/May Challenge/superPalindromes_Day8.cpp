/*
    Problem : Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
    Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].

    Example 1:
    Input: left = "4", right = "1000"
    Output: 4
    Explanation: 4, 9, 121, and 484 are superpalindromes.
    Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.

    Example 2:
    Input: left = "1", right = "2"
    Output: 1
    
    Constraints:
    1 <= left.length, right.length <= 18
    left and right consist of only digits.
    left and right cannot have leading zeros.
    left and right represent integers in the range [1, 1018].
    left is less than or equal to right.
*/

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