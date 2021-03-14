/*
 * Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction. 
	Input:
	N = 5, D = 2
	arr[] = {1,2,3,4,5}
	Output: 3 4 5 1 2
 * */


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



class Solution{
    public:
    
    void reverseHelper(int arr[], int start, int end){
        if(start == end)
            return ;
        int temp ;
        while(start<end){
            temp = arr[start] ;
            arr[start] = arr[end] ;
            arr[end] = temp ;
            start++ ; end-- ;
        }

    }
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        
        reverseHelper(arr, 0, d-1);
        reverseHelper(arr, d, n-1) ;
        reverseHelper(arr, 0, n-1) ;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends
