// Problem : https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int i = 0, j = 0, ans = 0 , k = 3;
        vector<int> char_map(26, 0) ;
        
        while(j < s.size()){
            char_map[s[j]-'a']++ ;
            
            // expanding the window
            if(j-i+1 < k)
                j++ ;
            else if(j-i+1 == k){
                bool found = true ;
                for(int p = 0 ; p < 26 ; p++){
                    if(char_map[p] > 1)
                        found = false ;
                    //cout<<"char_map[ "<<p<<" ] = "<<char_map[p]<<endl ;
                }
                
                if(found)
                    ans++ ;
                
                // slide the window
                char_map[s[i]-'a']-- ;
                i++ ;
                j++ ;
            }
        }
        
        return ans ;
    }
};