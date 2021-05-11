/*
    Problem : Count the number of prime numbers less than a non-negative number, n.

    Example 1:
    Input: n = 10
    Output: 4
    Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

    Example 2:
    Input: n = 0
    Output: 0

    Example 3:
    Input: n = 1
    Output: 0
    
    Constraints:
    0 <= n <= 5 * 106
*/

class Solution {
public:
    /*
    bool isPrime(int n){
        for(int i = 2 ; i*i <= n ; i++){
            if(n % i == 0)
                return false ;
        }
        return true ;
    }
    */
    
    int countPrimes(int n) {
        if(n <= 1)
            return 0 ;
        
        int primeCount = 0 ;
        vector<bool> sieve(n, true) ;
        
        /*
         // Brute Force 
        for(int i = 2 ; i < n ; i++){
            if(isPrime(i))
                primeCount++ ;   
        }
        */
        
        // Sieve of Eratosthenes
        for(int i = 2 ; i*i < n ; i++){
            if(sieve[i]){
                for(int j = 2 ; j * i < n ; j++)
                    sieve[j * i] = false ;
            }
        }
        
        for(int i = 2 ; i < n ; i++)
            if(sieve[i])
                primeCount++ ;
        
        return primeCount ;
    }
};