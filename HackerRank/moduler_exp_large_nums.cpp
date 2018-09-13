/* Modular exponentiation of large numbers */
#include <iostream>
#include <math.h>
using namespace std ;

unsigned int modular_exp(unsigned int a, unsigned int b, unsigned int c){

	if(b==0)
		return 1 ;
	else if(b%2)
		return (modular_exp(a,b-1,c) * (a%c))%c ;
	else{
		unsigned int y = modular_exp(a,b/2,c) ;
		return (y*y)%c ; 
	}
}
int main(){

	unsigned int a,b,c, result, T ;

	cin>>T ;
	for(int i=0 ; i<T ; i++){
		cin>>a>>b>>c ;

		result = modular_exp(a,b,c) ;

		cout<<result<<endl ;
	}
	
	return 0 ;
}