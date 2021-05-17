// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:

    long long int fact(unsigned int n){
        if(n == 0 || n == 1)
            return 1 ;
        long long int f = 1 ;
        for(int i = 2 ; i <= n ; i++)
            f *= i ;
        
        return f ;
    }
    
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        
        vector<long long int> dp(N+1, 0) ;
        dp[0] = 1 ;
        dp[1] = 1 ;
        unsigned int mod = 1000000007 ;
        
        // DP Solution
        for(int i = 2 ; i <= N ; i++){
            dp[i] = 0 ;
            for(int k = 0 ; k < i ; k++)
                dp[i] += (dp[k] * dp[i-k-1]) % mod ;
            dp[i] = dp[i] % mod ;
        }
        
        return dp[N] ;
        
        // Binomial coefficient solution
        // return fact(2*N) / (fact(N) * fact(N+1)) ;
    }
};

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends