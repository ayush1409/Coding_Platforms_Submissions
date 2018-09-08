#include <iostream>
#include <string>
#include <unordered_map>
using namespace std ;

bool check_valid_string(string s){

	unordered_map<char, int> umap ;
	int sum = 0 ;

	for(int i=0 ; i<s.length() ; i++){
		if(umap.find(s[i]) == umap.end())
			umap.insert({s[i],1}) ;
		else
			umap[s[i]] += 1 ;
	}
/*
	for(auto x : umap)
		cout<<x.first<<" : "<<x.second ;
*/
	int sum_freq = 0 ;

	for(auto it=umap.begin() ; it!=umap.end() ; it++){
		sum_freq += it->second ;
	}

	int avg_freq = sum_freq/umap.size() ;

	for(auto it=umap.begin() ; it!=umap.end() ; it++){
		if(it->second > avg_freq)
			sum += (it->second - avg_freq) ;
		if(sum > 1)
			return false ;
	}

	return true ;

}

int main(){

	string s ;

	cin>>s ;

	if(check_valid_string(s)) 
		cout<<"YES"<<endl ;
	else 
		cout<<"NO"<<endl ;

	return 0 ;
} 