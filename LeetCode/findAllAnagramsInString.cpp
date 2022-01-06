// Problem: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int i = 0, j = 0, count=0, k = p.size() ;
        unordered_map<char, int> mp ;
        vector<int> ans ;
        
        // creating the pattern map using string p
        for(int i = 0 ; i < p.size() ; i++){
            if(mp.find(p[i]) == mp.end()){
                mp.insert({p[i], 1}) ;
                count++ ;
            }
            else
                mp[p[i]]++ ;
        }
        
        
        while(j < s.size()){
            
            // expanding the window using j pointer
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]-- ;
                if(mp[s[j]] == 0)
                    count-- ;
            }
            
            if(j - i + 1 < k)
                j++ ;
            // when the window size reached
            else if(j - i + 1 == k){
                if(count == 0)
                    ans.push_back(i) ;
      
                // slide the window
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++ ;
                    if(mp[s[i]] == 1)
                        count++ ;
                }
                i++ ;
                j++ ;
            }
            //for(auto c : mp)
            //    cout<<c.first<<", "<<c.second<<endl ;
        }
        
        return ans ;
        
        /*
        Approach 2 : TLE, Time : O(nk)
        int i = 0, j = 0 ;
        vector<int> countWin(26, 0) ;
        vector<int> countp(26, 0) ;
        vector<int> answer ;
        
        int k = p.size() ; 
        
        for(int t = 0 ; t < p.size() ; t++)
            countp[p[t] - 'a']++ ;
        
        while(j < s.size()){
            countWin[s[j] - 'a']++ ;
            
            if(j-i+1 < k)
                j++ ;
            else if(j-i+1 == k){
                bool found = true ;
                for(int t = i ; t <= j ; t++)
                    if(countWin[s[t]-'a'] != countp[s[t]-'a'])
                        found = false ;
                if(found)
                    answer.push_back(i) ;
                
                // slide the window
                countWin[s[i] - 'a']-- ;
                i++ ;
                j++ ;
            }
        }
        
        return answer ;
        
        */
        
    }
};