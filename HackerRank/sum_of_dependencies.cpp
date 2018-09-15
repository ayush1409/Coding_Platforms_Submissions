#include <iostream>
using namespace std ;

int main(){

	unsigned int n,e,sumx ;

	int x,y,T ;

	cin>>T ;
	for(int k = 0 ; k<T ; k++){

		cin>>n>>e ;
		
		sumx = 0 ;
		// dynamically create 2D array
		int **arr = new int*[n];
		for(int i=0 ; i<n ; i++)
			arr[i] = new int[n] ;

		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++)
				arr[i][j]=0 ;
		}

		
		for(int i=0 ; i<e ; i++){
			cin>>x>>y ;
			arr[x][y] = 1 ;
		}

		// counting the number of out degrees 
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				sumx += arr[i][j] ;
			}
		}

		for(int i=0 ; i<n ; i++)
			delete[] arr[i] ;

		delete[] arr ;

		cout<<sumx<<endl ;
	
	}

	return 0 ;
}