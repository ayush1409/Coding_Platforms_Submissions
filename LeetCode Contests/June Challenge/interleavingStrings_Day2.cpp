class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        
        // coordinates are of the form [i, j], corresponding to the indexes in s1, s2
        stack<pair<int,int>> s ;
        s.push({0, 0});
		
        vector<vector<bool>> visited(s1.size()+1, vector<bool>(s2.size()+1, false)) ;
        
        while (!s.empty()) {
            pair<int,int> indexes = s.top();
            s.pop() ;
            int i = indexes.first, j = indexes.second;
            visited[i][j] = true;
			
			// we're at the bottom-rightmost coordinate; we're done!
            if (i == s1.size() && j == s2.size())
                return true;
            
			// check if we can increment i (traveling right on the graph)
            if (i < s1.size() && !visited[i + 1][j] && s1[i] == s3[i + j])
                s.push({i + 1, j});
            
			// check if we can increment j (traveling down on the graph)
            if (j < s2.size() && !visited[i][j + 1] && s2[j] == s3[i + j])
                s.push({i, j + 1});
        }
        
        return false;
    }
};