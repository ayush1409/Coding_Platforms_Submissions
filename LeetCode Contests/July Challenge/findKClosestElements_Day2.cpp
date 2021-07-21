class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        unsigned int n = arr.size() ;
        vector<int> diff(n) ;
        vector<int> result(k) ;
        
        for(unsigned int i = 0 ; i < n ; i++){
            if(arr[i] - x > 0)
                diff[i] = arr[i] - x ;
            else
                diff[i] = x - arr[i] ;
        }
        
        int l = 0, r = k-1 ;
        int sum = 0 ;
        
        for(int i = l ; i <= r ; i++)
            sum += diff[i] ;
        
        int minSum = sum ;
        
        for(int i = 0 ; i < k ; i++)
            result[i] = arr[i] ;
        
        while(r < n){        
        
            sum -= diff[l] ;
            l++ ;
            r++ ;
            if(r == n)
                break ;
            
            sum += diff[r] ;
            
            if(sum < minSum){
                cout<<minSum ;
                for(int i = 0 ; i < k ; i++)
                    result[i] = arr[i+l] ;
                minSum = sum ;
            }
        }
        
        return result ;
    }
};