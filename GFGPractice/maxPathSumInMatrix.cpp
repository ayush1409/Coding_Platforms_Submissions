// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int max(int a, int b, int c){
        return a > b ? (a > c ? a : c) : (b > c ? b : c) ;
    }
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0)) ;
        int x, y, z ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                x = (i-1 >= 0 && j-1 >= 0) ? dp[i-1][j-1] : 0 ;
                y = (i-1 >= 0) ? dp[i-1][j] : 0 ;
                z = (i-1 >= 0 && j+1 < n) ? dp[i-1][j+1] : 0 ;
                
                dp[i][j] = Matrix[i][j] + max(x, y, z) ;
            }
        }
        
        int maxPath = INT_MIN ;
        
        for(int j = 0 ; j < n ; j++){
            if(dp[n-1][j] > maxPath)
                maxPath = dp[n-1][j] ;
        }
        
        return maxPath ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends