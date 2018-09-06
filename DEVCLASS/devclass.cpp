
// input string and make listB and listG for unpositional B and G --> O(N)
// store the index positions in lists 
// swap the elements according to lists -> O(N/2)
// overall complexity : O(N)
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <math.h>
using namespace std ;

void make_lists(list<int> &listA, list<int> &listB, string s, char first_char){// first_char denotes the char should be at 1st position 
	
	if(first_char == 'B'){
		for(int i ; i<s.size() ; i++){
			if(s[i] == 'G' & !(i%2))
				listB.push_back(i) ;
			else if(s[i] == 'B' & i%2)
				listA.push_back(i) ;
		}
	}
	else{
		for(int i ; i<s.size() ; i++){
			if(s[i] == 'B' & !(i%2))
				listB.push_back(i) ;
			else if(s[i] == 'G' and i%2)
				listA.push_back(i) ;
		}
	}

}
int main(){

	unsigned int t,T, cost;
	int nA,nB ;
	string s ;
	cin>>T ;
	list<int> listA, listB ;

	for(unsigned int k=0 ; k<T ; k++){

		cin>>t>>s ;

		cost = 0 ;
		nA = count(s.begin(), s.end(), 'B') ;
		nB = count(s.begin(), s.end(), 'G') ;

		if(abs(nA-nB) > 1){
			cout<<-1<<endl ;
			continue ;
		}

		
		// string will start with 'A' 
		if(nA > nB){
			make_lists(listA, listB, s, 'B') ;
		}
		// string starts with 'B'
		else if(nA < nB){
			make_lists(listA, listB, s, 'G') ;
		}
		// can start with either 'A' or 'B'
		else{
			make_lists(listA, listB, s, s[0]) ;	
		}

		// swap the elements now
		list<int>::iterator i,j ;
		i = listA.begin() ;
		j = listB.begin() ;

		while(i != listA.end() & j != listB.end()){
			swap(s[*i], s[*j]) ;
			cost += pow(abs(*i-*j),t) ;
			i++ ;
			j++ ;
		}
		//cout<<"\n final string : "<<s<<endl ;
		cout<<cost<<endl ;
		
		listA.erase(listA.begin(), listA.end()) ;
		listB.erase(listB.begin(), listB.end()) ; 

	}
	return 0 ;
}