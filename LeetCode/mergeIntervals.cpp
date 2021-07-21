class Solution {
// Problem: https://leetcode.com/problems/merge-intervals/

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0] ;
        }) ;
        
        vector<vector<int>> result ;
        vector<int> buffer = intervals[0] ;
        
        for(int i = 0 ; i < intervals.size() ; i++){
            
            if(buffer[1] >= intervals[i][0]){
                // merge buffer with intervals[i]
                buffer[1] = max(buffer[1], intervals[i][1]) ;
                buffer[0] = min(buffer[0], intervals[i][0]) ;
            }
            else{
                result.push_back(buffer) ;
                buffer = intervals[i] ;
            }
        }
        result.push_back(buffer) ;
        
        return result ;
    }
};