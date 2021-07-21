// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    
    // Using BFS to detect a cycle
    bool isCyclicHelper(vector<int> adj[], int i, vector<bool> &visited){
        queue<int> q ;
	    q.push(i) ;
	    
	    while(!q.empty()){
	        int curr = q.front() ;
	        q.pop() ;
	        
	        if(visited[curr])
	            return true ;
	           
	       visited[curr] = true ;
	       
	       for(auto nbr : adj[curr]){
	           if(!visited[nbr])
	                q.push(nbr) ;
	       }
	    }
	    return false ;
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool> visited(V, false) ;
	    
	    for(int i = 0 ; i < V ; i++)
	        if(!visited[i] && isCyclicHelper(adj, i, visited))
	            return true ;
	   
	    return false ;
	            
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends