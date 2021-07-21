// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        // Using tabulation
        unsigned int MOD = 1000000007 ;
        vector<int> dp(n+1, 0) ;
        dp[0] = 1 ;
        
        for(int i = 1 ; i <= n ; i++){
            if(i == 1){
                dp[i]= dp[i-1] % MOD ;
            }
            else {
                dp[i] = (dp[i-1] % MOD + dp[i-2] % MOD) % MOD ;
            }
        }
        
        return dp[n] ;
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends