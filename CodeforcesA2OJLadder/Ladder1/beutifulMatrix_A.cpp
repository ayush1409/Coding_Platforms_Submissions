// Problem : https://codeforces.com/problemset/problem/263/A
#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<vector<int>> m(5, vector<int>(5)) ;
	int row = 0, col = 0 ;

	for(int i = 0 ; i < 5 ; i++){
		for(int j = 0 ; j < 5 ; j++)
			cin>>m[i][j] ;
	}

	for(int i = 0 ; i < 5 ; i++){
		for(int j = 0 ; j < 5 ; j++)
			if(m[i][j]){
				row = i ;
				col = j ;
				break ;
			}
	}
	cout<<abs(row-2) + abs(col-2) ;
}
