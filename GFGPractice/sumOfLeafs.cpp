#include <bits/stdc++.h>
using namespace std ;
/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */

void sumLeafs(Node *root, vector<int> &sumVec){
    if(root == NULL)
        return ;
    
    if(root -> left == NULL && root -> right == NULL){
        sumVec.push_back(root -> data) ;
        return ;
    }
    
    sumLeafs(root -> left, sumVec) ;
    sumLeafs(root -> right, sumVec) ;
    
}

/*You are required to complete below method */
int sumOfLeafNodes(Node *r ){
     
     vector<int> sumVec ;
     int sum = 0 ;
     
     sumLeafs(r, sumVec) ;
     
     for(int i = 0 ; i < sumVec.size() ; i++)
        sum += sumVec[i] ;
    
    return sum ;
}