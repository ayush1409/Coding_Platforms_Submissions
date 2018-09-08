#include <iostream>
#include <vector>
using namespace std ;


void apply_rotaion(vector<int> a,int d){
		
	vector<int> front(a.begin(), a.begin() + d) ;
	vector<int> back(a.begin()+d, a.end()) ;

	back.insert(back.end(), front.begin(), front.end()) ;

	for(auto x : back)
		cout<<x<<" " ;
}

int main(){

	int n,d,x ;
	cin>>n>>d ;
	vector<int> a ;

	for(int i=0 ; i<n ; i++){
		cin>>x ;
		a.push_back(x) ;
	}

	apply_rotaion(a,d) ;
	
	cout<<endl ;
	return 0 ;
}