// Problem : https://codeforces.com/problemset/problem/266/B

#include <iostream>
#include <bits/stdc++.h>
#include <typeinfo>
using namespace std ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, time = 0;
    cin>>n>>t ;

    vector<char> students(n) ;

    for(int i = 0 ; i < n ; i++){
    	cin>>students[i];
    }

    int i = 0,j ;
    while(i < n){
    	while(i < n && students[i] == 'G')
    		i++ ;
    	if(i == n)
    		break ;
    	
    	j = i + 1 ;
    	while(j < n && students[j] == 'B')
    		j++ ;
    	if(j == n)
    		break ;
    	
    	students[i] = 'G' ;
    	students[j] = 'B' ;
    	time++ ;

    	if(time == t)
    		break ;

    	i = j ;
    } 
*/
    while(time < t){
	    for(int i = 0 ; i < n-1 ;){
	    	if(students[i] == 'B' && students[i+1] == 'G'){
	    		students[i] = 'G' ;
	    		students[i+1] = 'B' ;
	    		i += 2 ;
	    	}
	    	else
	    		i++;
	    }
	    time++ ;
	}

   	for(int i = 0 ; i < n ; i++)
   		cout<<students[i] ;
   	
	return 0 ;
}
