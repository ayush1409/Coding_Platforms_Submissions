// Problem : https://cses.fi/problemset/task/1634

#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std ;

int minimumCoins(vector<int> &coins, int target){
	vector<int> dp(target+1, -1) ;
	dp[0] = 0 ;
	int minCoins ;
	for(int x = 1 ; x <= target ; x++){
		minCoins = INT_MAX ;
		for(int i = 0 ; i < coins.size() ; i++){
			if(x - coins[i] < 0)
				break ;
			minCoins = min(minCoins, dp[x - coins[i]]) ;
		}

		if(minCoins == INT_MAX)
			dp[x] = 0 ;
		else
			dp[x] = minCoins + 1 ;
	}

	return dp[target] ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,x,a ;
	cin >> n >> x ;

	vector<int> coins(n) ;
	for(int i = 0 ; i < coins.size() ; i++){
		cin>>a ;
		coins[i] = a ;
	}
	sort(coins.begin(), coins.end()) ;
	
	if(x < coins[0])
		cout<<-1 ;
	else
		cout<<minimumCoins(coins, x) ;
	
	return 0 ;

}
