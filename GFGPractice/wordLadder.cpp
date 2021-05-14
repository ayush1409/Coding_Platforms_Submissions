class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        int wordSize = startWord.size() ;
        unordered_set<string> s ;
       
        if(startWord == targetWord)
            return 0 ;
        
        unsigned int len = 0, n;
        
        for(int i = 0 ; i < wordList.size() ; i++){
            s.insert(wordList[i]) ;
        }
        
        if(s.find(targetWord) == s.end())
            return 0 ;
        
        queue<string> q ;
        q.push(startWord) ;
        
        while(!q.empty()){
            len++ ;
            n = q.size() ;
            for(int j = 0 ; j < n ; j++){
                string curr = q.front() ;
                q.pop() ;
                
                for(int i = 0 ; i < curr.size() ; i++){
                    char org = curr[i] ;
                    for(char ch = 'a' ; ch <= 'z' ; ch++){
                        curr[i] = ch ;
                        if(curr == targetWord)
                            return len + 1 ;
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