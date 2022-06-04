// Problem: https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void subsetSumUtil(int i, int sum, const vector<int> &arr, vector<int> &sum_list){
        
        int N = arr.size() ;
        
        if(i <= N){
            if(i == N){
                sum_list.push_back(sum) ;
                return ;
            }
        
            subsetSumUtil(i+1, sum, arr, sum_list) ; 
            subsetSumUtil(i+1, sum + arr[i], arr, sum_list) ;
        }
    }


    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sum_list ;
        int sum = 0 ;
        
        sort(arr.begin(), arr.end()) ;
        
        subsetSumUtil(0, sum, arr, sum_list) ;
        
        return sum_list ;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
