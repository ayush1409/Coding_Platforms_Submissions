class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size() ;
        unordered_map<int, int> mp ;
        vector<pair<int, int>> v ;
        
        for(auto x : arr){
            if(mp.find(x) == mp.end())
                mp.insert({x, 1}) ;
            else
                mp[x]++ ;
        }
        
        for(auto x: mp){
            v.push_back(x) ;
        }
        
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            return a.second > b.second ;}) ;
        
        int r = n, ans = 0 ;
        for(auto x: v){
            if(r <= n/2)
                break ;
            r -= x.second ;
            ans++ ;
        }
        
        return ans ;
    }
};