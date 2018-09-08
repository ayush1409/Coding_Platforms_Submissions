#include <iostream>
#include <string>
#include <unordered_map>
using namespace std ;


int check_anagram(string s){
	if(s.size()%2)
		return -1 ;

	int count = 0 ;
	unordered_map<char,int> umap1 ;
	
	for(int i=0 ; i<s.size()/2 ; i++){
		if(umap1.find(s[i]) == umap1.end()){
			umap1.insert({s[i],1}) ;
		}
		else
			umap1[s[i]] += 1 ;
	}
	
	// case when 2nd half of string has unmatched characters
	for(int i=s.size()/2 ; i<s.size() ; i++){
		if(umap1.find(s[i]) != umap1.end() && umap1.find(s[i])->second != 0){
			umap1[s[i]] -= 1 ;
		}
		else
			count++ ;
	}
/*
	for(auto x : umap1){
		if(x.second > 0)
			count += x.second ;
	}
*/
	return count ;
}

int main(){
	string s ;
	int T, result ;

	cin>>T;
	for(int i=0 ; i<T ; i++){
		cin>>s ;

		result = check_anagram(s) ;
	
		if(result != -1) 
			cout<<result<<endl ;
		else
			cout<<-1<<endl ;
	}

	return 0 ;
}