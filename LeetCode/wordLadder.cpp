// Problem : https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord)
            return 0 ;
        unsigned int distance = 0,n ;
        unordered_set<string> s ;
        
        for(int i = 0 ; i < wordList.size() ; i++)
            s.insert(wordList[i]) ;
        
        if(s.find(endWord) == s.end())
            return 0 ;
        
        queue<string> q ;
        q.push(beginWord) ;
        
        while(!q.empty()){
            distance++ ;
            n = q.size() ;
            for(int j = 0 ; j < n ; j++){
                string curr = q.front() ;
                q.pop() ;
                for(int i= 0 ; i < curr.size() ; i++){
                    char org = curr[i] ;
                    for(char ch = 'a' ; ch <= 'z' ; ch++){
                        curr[i] = ch ;
                        if(curr == endWord) 
                            return distance + 1;
                        if(s.find(curr) == s.end())
                            continue ;
                        
                        s.erase(curr) ;
                        q.push(curr) ;
                    }
                    curr[i] = org ;
                }
            }
        }
        return 0 ;
    }
};