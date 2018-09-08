#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <unordered_set> 
using namespace std ;

bool check_substring(string s1, string s2){
    unordered_set<char> uset ;

    for(int i=0 ; i<s1.length() ; i++)
        uset.insert(s1[i]) ;

    for(int i=0 ; i<s2.length() ; i++){
        if(uset.find(s2[i]) != uset.end())
            return true ;
    }
    return false ;
}
int main(){
    string s1,s2 ;
    int T ;

    unordered_set<string> uset ;

    cin>>T ;
    for(int i=0 ; i<T ; i++){
    
        cin>>s1>>s2 ;
    
        if(check_substring(s1,s2)) 
            cout<<"YES"<<endl ;
        else
            cout<<"NO"<<endl ;
    }

    return 0 ;
}