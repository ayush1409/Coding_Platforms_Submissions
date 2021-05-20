// Problem : https://codeforces.com/problemset/problem/32/B

#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s, result ;
    cin>>s ;
    int n = s.size() ;

    for(int i = 0 ; i < n ;){
    	if(s[i] == '.'){
    		result += '0' ;
    		i++ ;
    	}
    	else if(i < n-1 && s[i] == '-' && s[i+1] == '.'){
    		result += '1' ;
    		i += 2 ;
    	}
    	else if(i < n-1 && s[i] == '-' && s[i+1] == '-'){
    		result += '2' ;
    		i += 2 ;
    	}
    }
    
    cout<<result ;
	return 0 ;
}
