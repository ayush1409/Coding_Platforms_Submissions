// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
    long long int i = 0, j = 0 ;
    deque<long long int> q ;
    vector<long long int> result ;
    
    while(j < N){
        // store the element in queue if negative
        if(A[j] < 0)
            q.push_back(A[j]) ;
            
        // expanding the window
        if(j-i+1 < k)
            j++ ;
        
        // when we hit the window size
        else if(j-i+1 == k){
            
            // If the window doesn't contain any negative number
            if(q.empty())
                result.push_back(0) ;
            else
                result.push_back(q.front()) ;
            
            // sliding the window
            if(A[i] == q.front())
                q.pop_front() ;
            i++ ;
            j++ ;
        }
    }
    
    return result ;
 }