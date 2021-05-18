/*
    Problem : Given a list of words, each word consists of English lowercase letters.
    Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2. For example, "abc" is a predecessor of "abac".
    A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.
    
    Return the longest possible length of a word chain with words chosen from the given list of words.

    Example 1:
    Input: words = ["a","b","ba","bca","bda","bdca"]
    Output: 4
    Explanation: One of the longest word chain is "a","ba","bda","bdca".

    Example 2:
    Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
    Output: 5

    Constraints:
    1 <= words.length <= 1000
    1 <= words[i].length <= 16
    words[i] only consists of English lowercase letters.
*/

/*class Solution {
public:
    int max(int x, int y){
        return x > y ? x: y ;
    }
    string::iterator removeChar(string &s, char ch){
        for(auto it = s.begin() ; it != s.end() ; it++)
            if(*it == ch){
                s.erase(it) ;
                return it ;
            }
        //cout<<s<<endl ;
        return s.end();
    }
    
    bool isAnagram(string &s1, string &s2){
        unordered_set<char> s ;
        for(auto x: s1)
            s.insert(x);
        
        for(int i = 0 ; i < s2.size() ; i++){
            if(s.find(s2[i]) == s.end())
                return false ;
            s.erase(s2[i]) ;
        }
        
        return true ;
    }
    int longestStrChain(vector<string>& words) {
        vector<int> length(words.size(), 0) ;
        
        int minLength = INT_MAX ;
        for(auto x : words)
            if(x.size() < minLength)
                minLength = x.size() ;
        
        sort(words.begin(), words.end(), [](string &i,string &j) {
            return i.size() < j.size() ;
        }) ;
        
        for(int i = 0 ; i < length.size() ; i++){
            if(words[i].size() == minLength)
                length[i] = 1 ;
            
        }
        /*
        cout<<minLength ;
        cout<<"words list : " ;
        for(auto x : words)
            cout<<x<<" " ;
        cout<<endl ;
        */
/*
        for(int i = 0 ; i < words.size() ; i++){
            for(int j = i+1 ; j < words.size() ; j++){
                if(words[j].size() - words[i].size() != 1)
                    continue ;
                cout<<"i : "<<words[i]<<", j: "<<words[j]<<endl ;
                for(int k = 0 ; k < words[j].size() ; k++){
                    char ch = words[j][k] ;
                    auto it = removeChar(words[j], ch) ;
                    if(words[i] == words[j])
                        length[j] = max(length[j], length[i]+1) ;
                    words[j].insert(it, ch) ;
                }
                cout<<"i : "<<words[i]<<", j: "<<words[j]<<endl<<endl ;
                
            }
        }
       
        
        cout<<"Length array : ";
        for(auto x : length)
            cout<<x<<" " ;
        cout<<endl ;
        
        int i = length.size()-1 ;
        for(; i >= 0 ; i--)
            if(length[i] != 0)
                break ;
        if(i >= 0)
            return length[i] ;
        else
            return 0 ;
    }
};
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<unordered_set<string>> W(17);
        for (auto word : words) 
            W[word.size()].insert(word);
        unordered_map<string, int> dp;
        int best = 1;
        for (int i = 16; i; i--) {
            if (W[i-1].empty()) continue;
            for (auto word : W[i]) {
                int wVal = dp[word] ? dp[word] : 1;
                for (int j = 0; j < word.size(); j++) {
                    string pred = word.substr(0,j) + word.substr(j+1);
                    int pVal = dp[pred] ? dp[pred] : 1;
                    if (W[i-1].find(pred) != W[i-1].end() && wVal >= pVal) {
                        dp[pred] = wVal + 1;
                        best = max(best, wVal + 1);
                    }
                }
            }
        }
        return best;
    }
};