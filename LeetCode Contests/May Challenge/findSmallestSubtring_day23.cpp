class Solution {
public:

    void dfs(size_t i, vector<vector<int>>& overlap, int bitmask, vector<vector<int>>& dp, vector<vector<int>>& next) {
        if (dp[i][bitmask] >= 0)
            return;
        size_t n = overlap.size();
        bitmask ^= (1 << i);
        int remain_length = -1;
        int next_node = -1;
        for (size_t j = 0; j < n; ++j) {
            if (!((1 << j) & bitmask)) {
                dfs(j, overlap, bitmask, dp, next);
                if (overlap[i][j] + dp[j][bitmask] > remain_length) {
                    remain_length = overlap[i][j] + dp[j][bitmask];
                    next_node = j;
                }
            }
        }
        bitmask ^= (1 << i);
        dp[i][bitmask] = max(0, remain_length);
        next[i][bitmask] = next_node;
        return;
    }

    //build the overlap graph
    void update(size_t i, size_t j, vector<string>& words, vector<vector<int>>& overlap) {
        if (i == j) 
            return;
        size_t n1 = words[i].size();
        size_t n2 = words[j].size();
        size_t n = min(n1, n2);
        int count = 0;
        for (size_t k = n; k > 0; --k) {
            if (words[i].substr(n1 - k) == words[j].substr(0, k)) {
                overlap[i][j] = k;
                return;
            }
        }
    }
    
    string shortestSuperstring(vector<string>& words) {
        size_t n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n)) ;
        
        for(size_t i = 0 ; i < n ; i++)
            for(size_t j = 0 ; j < n ; j++)
                update(i, j, words, overlap) ;
        
        vector<vector<int>> dp(n, vector<int>(1 << n, -1)) ;
        vector<vector<int>> next(n, vector<int>(1 << n, -1)) ;
        
        int max_length = -1 ;
        int curr = -1 ;
        
        vector<int> max_path;
        for (size_t i = 0; i < n; ++i) {
            dfs(i, overlap, 0, dp, next);
            if (dp[i][0] > max_length) {
                max_length = dp[i][0];
                curr = i;
            }
        }
        
        vector<size_t> path;
        path.push_back(curr);
        int bitmask = 0;
        while (next[curr][bitmask] >= 0) {
            path.push_back(next[curr][bitmask]);
            bitmask ^= (1 << curr);
            curr = path.back();
        }
        
        string result = words[path[0]];
        for (size_t i = 1; i < n; ++i) 
            result += words[path[i]].substr(overlap[path[i-1]][path[i]]);
        return result;
    }
};
