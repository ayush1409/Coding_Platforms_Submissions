// Problem: https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    map<int, int> m ;
    int n1 = A.size() ;
    int xr = 0, y, count = 0;
    for(int i = 0 ; i < n1 ; i++){
        xr = xr ^ A[i] ;

        if(xr == B)
            count++ ;

        y = xr ^ B ;
        if(m.find(y) != m.end())
            count += m[y] ;
        
        if(m.find(xr) == m.end())
            m[xr] = 1;
        else
            m[xr]++ ;
    }

    return count ;
}
