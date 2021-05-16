// Problem : https://codeforces.com/problemset/problem/69/A
#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n ;
	cin>>n ;
	vector<vector<int>> vec(n, vector<int>(3)) ;
	int sumx = 0 , sumy = 0, sumz = 0;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 3 ; j++)
			cin>>vec[i][j] ;
	}

	for(int i = 0 ; i < n ; i++){
		sumx += vec[i][0] ;
		sumy += vec[i][1] ;
		sumz += vec[i][2] ;
	}

	if(!sumx && !sumy && !sumz)
		cout<<"YES" ;
	else
		cout<<"NO" ;

}
