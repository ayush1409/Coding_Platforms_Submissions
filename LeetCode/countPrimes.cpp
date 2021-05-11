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