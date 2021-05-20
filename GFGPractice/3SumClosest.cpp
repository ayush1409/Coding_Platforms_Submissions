/*
    Given an array A[] of N integers and an integer X. The task is to find the sum of three integers in A[] such that it is closest to X.

    Example 1:
    Input:
    N = 4
    A[] = {-1 , 2, 1, -4}
    X = 1
    Output: 2
    Explaination: 
    Sums of triplets:
    (-1) + 2 + 1 = 2
    (-1) + 2 + (-4) = -3
    2 + 1 + (-4) = -1
    2 is closest to 1.

    Example 2:
    Input:
    N = 5
    A[] = {1, 2, 3, 4, -5}
    X = 10
    Output: 9
    Explaination: 
    Sums of triplets:
    1 + 2 + 3 = 6
    2 + 3 + 4 = 9
    1 + 3 + 4 = 7
    ...
    9 is closest to 10.

    Your Task:
    You don't need to read input or print anything. Your task is to complete the function closest3Sum() which takes the array Arr[] and its size N and X as input parameters and returns the sum which is closest to X.
    NOTE: If there exists more than one answer then return the maximum sum.
    Expected Time Complexity: O(N2)
    Expected Auxiliary Space: O(1)

    Constraints:
    3 ≤ N ≤ 103
    -103 ≤ Arr[i] ≤ 103
    -104 ≤ X ≤ 104
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int findDiff(int x, int y){
        return x > y ? x - y : y - x ;
    }
    
    int closest3Sum(int A[], int N, int X)
    {
        int minDiff = INT_MAX, sum, result, diff ;
        sort(A, A+N) ;
        
        for(int a = 0 ; a < N ; a++){
            int b = a + 1, c = N-1 ;
            while(b<c){
                sum = A[a] + A[b] + A[c] ;
                diff = findDiff(X, sum) ;
                
                if(diff < minDiff){
                    minDiff = diff ;
                    result = sum ;
                }
                
                if(A[b] + A[c] > X - A[a])
                    c-- ;
                else
                    b++ ;
            }
        }
        
        return result ;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}  // } Driver Code Ends