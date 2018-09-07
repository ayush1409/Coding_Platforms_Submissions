/* Codechef problem : GERMANDE */
/* overall time complexity : O(N)*/
#include <iostream>
using namespace std ;

int check_leader(int arr[], int o1, int o2){
	int N = o1*o2 ;
	int *c = new int[N] ;
	cout<<"\nN : "<<N ;
	int win_states = 0 ;
	int l,r ;
	c[0] = arr[0] ;
	cout<<"\n c[0] : "<<c[0]<<endl ;
	cout<<"\n sum array : " ;
	for(int i=1 ; i<N ; i++){
		c[i] = arr[i] + c[i-1] ;
		cout<<c[i] ;
	}
	int i=0 ; 

	while(1){
		win_states = 0 ;
		i++ ;
		if(i >= o2)
			break ;
		l = i ; 
		r = (l+o2)%N ;
		while(1){
			
			if((c[r]-c[l]) < o2/2){
				break ;
			}
			win_states++ ;
			l = (r+1) ;
			r = (l+o2)%N ;
		}
		if(win_states > o1/2)
			return 1 ;
	}

	return 0 ;
}

int main(){

	int o1,o2,N ;
	cin>>o1>>o2 ;
	N = o1*o2 ;

	int *arr = new int[N] ;

	for(int i=0 ; i<N ; i++){
		cin>>arr[i] ;
	}

	int result = check_leader(arr,o1,o2) ;

	if(result)
		cout<<"One wins"<<endl ;
	else
		cout<<"One does not win"<<endl ;
	return 0 ;
}