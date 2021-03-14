// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}// } Driver Code Ends

/*you are required to complete this method*/
int convertFive(int n) {
    // Your code here
    
    int r = n ;
    int d=0 ;
    while(r>0){
        if(r%10 == 0)
            n += 5 * pow(10, d) ;
        r /= 10 ;
        d++ ;
    }
    
    return n ;
}
