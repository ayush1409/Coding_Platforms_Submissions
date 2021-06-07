// Code is correct but Online Judge giving ambigous result

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void paths(vector<vector<int>> &maze, int i, int j, vector<string> &result, int n, string path){
        if(i == n-1 && j == n-1){
            result.push_back(path) ;
            return ;
        }            
        if(i < 0 || i >= n || j < 0 || j >= n)
            return  ;
        
        maze[i][j] = 0 ;
        
        if(i < n-1 && maze[i+1][j] && !visited[i+1][j]){
            path.push_back('D') ;
            paths(maze, i+1, j, result, n, path) ;
            path.pop_back() ;
        }
        if(j < n-1 && maze[i][j+1] && !visited[i][j+1]){
            path.push_back('R');
            paths(maze, i, j+1, result, n, path) ;
            path.pop_back() ;
        }
        if(i > 0 && maze[i-1][j] && !visited[i-1][j]){
            path.push_back('U');
            paths(maze, i-1, j, result, n, path) ;
            path.pop_back() ;
        }
        if(j > 0 && maze[i][j-1] && !visited[i][j-1]){
            path.push_back('L') ;
            paths(maze, i, j-1, result, n, path) ;
            path.pop_back() ;
        }
        maze[i][j] = 1 ;
        
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> result ;
        string path ;
        // vector<vector<bool>> visited(n, vector<bool>(n, false)) ;
    
        if(!maze[0][0])
            return vector<string>(1, "-1") ;
            
        paths(maze, 0, 0, result, n, path) ;
        
        if(result.empty()){
            result.push_back("-1") ;
        }
        return result ;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends