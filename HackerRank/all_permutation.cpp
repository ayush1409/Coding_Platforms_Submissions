#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#define MAX_LIMIT 6 
using namespace std ;

void swap(char *x, char *y){
	char temp ;
	temp = *x ;
	*x = *y ;
	*y = temp ;
}

void all_permutaion(char *c, int l,int r){

	if(l==r)
		printf("%s ", c);
	else{
		for(int i=l ; i<=r ; i++){
			swap((c+l), (c+i)) ;
			all_permutaion(c, l+1, r) ;
			swap((c+l), (c+i));
		}
	}
}


int main(){

	char s[MAX_LIMIT] ;

	unsigned int T ;
	//all_permutaion(s, 0,s.length()-1) ;
	//fgets(s,stdin) ;
	//gets(s) ;		// works here
	//cout<<s<<strlen(s)<<endl ;
	cin>>T ;
	for(unsigned int i=0 ; i<T ; i++){
		scanf("%s", s) ;
		all_permutaion(s,0,strlen(s)-1) ;
		cout<<endl ;
	}

	cout<<endl ;
	//printf("%s\n", s);
	return 0 ;
}