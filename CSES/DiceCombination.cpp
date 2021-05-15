// Problem : https://cses.fi/problemset/task/1633/

#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int max = 1000000007 ;
    unsigned int n ;
    cin >> n ;
    vector<unsigned int> dp(n+1, 0) ;
    dp[0] = 1 ;

    for(int i = 1 ; i <= n ; i++){
    	for(int x = 1 ; x <= 6 ; x++){
    		if(i < x)
    			break ;
    		dp[i] = (dp[i] + dp[i-x]) % max ;
    	}
    }
    cout << dp[n];
	return 0 ;

}
