// Problem: https://bit.ly/339fFb7

#include <bits/stdc++.h> 
void merge(long long *arr, int left, int mid, int right,long long &invCount){
    int n1 = mid - left;
    int n2 = right - mid + 1;
  
    vector<long long> A(n1), B(n2) ;
    for(int i = left ; i < mid ; i++){
        A[i-left] = arr[i] ;
    }
    for(int i = mid ; i <= right ; i++){
        B[i-mid] = arr[i] ;
    }
    
    // perform merge
    int i = 0, j = 0, k = left ;
    while(i < n1 && j < n2){
        if(A[i] < B[j])
            arr[k++] = A[i++];
        else{
            arr[k++] = B[j++] ;
            invCount += (n1 - i) ;
        }
    }
    
    while(i < n1){
        arr[k++] = A[i++] ;
    }
    
    while(j < n2){
        arr[k++] = B[j++] ;
    }
}


void mergeSort(long long *arr, int left, int right, long long &invCount){
    if(left < right){
        int mid = left + (right - left)/2 ;
        mergeSort(arr, left, mid, invCount) ;
        mergeSort(arr, mid+1, right, invCount) ;
        merge(arr, left, mid+1, right, invCount) ;
    }
}

long long getInversions(long long *arr, int n){
    long long invCount = 0 ;
    mergeSort(arr, 0, n-1, invCount) ;
    
    return invCount ;
}