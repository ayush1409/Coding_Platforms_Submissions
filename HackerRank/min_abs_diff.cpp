#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std ;

int min_abs_diff(int arr[], int n){
	if(n==1)
		return arr[0] ;

	sort(arr, arr+n) ;
	int abs_diff = abs(arr[1] - arr[0]) ;

	for(int i=2 ; i<n ; i++){
		if(abs_diff > abs(arr[i] - arr[i-1]))
			abs_diff = abs(arr[i] - arr[i-1]) ;
	}

	return abs_diff ;
}

int main(){
	int n ;
	cin>>n ;

	int *arr = new int[n] ;
	for(int i=0 ; i<n ; i++)
		cin>>arr[i] ;

	int min_diff = min_abs_diff(arr,n) ;
	
	cout<<min_diff<<endl ;

	return 0 ;
}