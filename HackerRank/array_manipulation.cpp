#include <iostream>
using namespace std ;


unsigned int find_max(unsigned int freq_count[], int l, int r){
	
	int max_pos = l ;

	for(int i=l ; i<=r ; i++){
		if(freq_count[i] > freq_count[max_pos])
			max_pos = i ;
	}

	return max_pos ;
	/*
	// case 1: single element
		if(l==r)
			return l ;

	// case 2: more then one element
		int mid = l + (r-l)/2 ;
		unsigned int max_l = find_max(arr,l,mid) ;
		unsigned int max_r = find_max(arr,mid+1,r) ;

		if(max_l >= max_r)
			return max_l ;
		else
			return max_r ;
	*/
}

int main(){

	unsigned int m,n,a,b ;
	int k ;
	cin>>n>>m ;

	unsigned long long int *arr = new unsigned long long int[n] ;
	unsigned int *freq_count = new unsigned int[n] ;

	for(int i=0 ; i<n ; i++){
		arr[i]=0 ;
		freq_count[i] = 0 ;
	}

	for(int i=0 ; i<m; i++){
		cin>>a>>b>>k ;

		for(int j=a-1 ; j<b ; j++){
			arr[j] += k ;
			freq_count[j] += 1 ;
		}
	}
/*
	for(int i = 0 ; i<n ; i++)
		cout<<freq_count[i]<<" " ;
*/
	int max = find_max(freq_count,0,n-1) ;

	cout<<arr[max]<<endl ;

	return 0 ;
}