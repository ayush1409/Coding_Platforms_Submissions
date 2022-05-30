// Problem: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
        int S = 0, maxLen = 0;
        unordered_map<int, int> umap ;
        
        for(int i = 0 ; i < n ; i++){
            S += A[i] ;
            
            if(S == 0)
                maxLen = max(maxLen, i+1) ;
            else if(umap.find(S) != umap.end())
                maxLen = max(maxLen, i - umap[S]) ;
            else
                umap[S] = i ;
        }
        
        return maxLen ;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends