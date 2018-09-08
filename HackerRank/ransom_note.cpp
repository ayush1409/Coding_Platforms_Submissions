#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std ;

int main(){
	int x1,x2 ;				// x1 : magazine size, x2 : note size
	bool can_make = true ;
	unordered_map<string, int> umap ;
	string temp ;

	cin>>x1>>x2 ;
	vector<string> note, magazine ;

	for(int i=0 ; i<x1 ; i++){
		cin>>temp ;
		magazine.push_back(temp) ;
	}
	for(int i=0 ; i<x2 ; i++){
		cin>>temp ;
		note.push_back(temp) ;
	}

	// create map : (string -> count) for magazine

	for(int i=0 ; i<x1 ; i++){
		if(umap.find(magazine[i]) == umap.end())
			umap.insert({magazine[i],1}) ;
		else
			umap[magazine[i]] += 1 ;
	}  
/*
	for(auto& x : umap)
		cout<<x.first<<" "<<x.second<<endl ;
	cout<<endl ;
*/

	// loop over to check existance of word in magazine
	for(int i=0 ; i<x2 ; i++){
		if(umap.find(note[i]) == umap.end() || umap[note[i]] == 0){
			cout<<"No" ;
			can_make = false ;
			break ;
		}
		else{
			umap[note[i]] -= 1 ;
		}
	}

	if(can_make)
		cout<<"Yes" ;

	return 0 ;
}