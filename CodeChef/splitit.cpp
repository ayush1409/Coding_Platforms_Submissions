#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n ;
    string s ;
    char ch ;
    bool found ;
    cin>>t ;

    while(t--){
    	cin>>n>>s ;
    	found = false ;
    	ch = s[s.size()-1] ;
    	for(int i = 0 ; i <= s.size() - 2 ; i++){
    		if(s[i] == ch){
    			found = true ;
    			cout<<"YES\n" ;
    			break ;
    		}
    	}
    	if(!found)
    		cout<<"NO\n" ;
    }
	return 0 ;

}
