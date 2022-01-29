// Problem: https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {
public:
    class UnionFind{
        public: 
        
        UnionFind(int n) : root(n), rank(n){
            for(int i = 0 ; i < n ; i++){
                root[i] = i ;
                rank[i] = 1 ;
            }
        }
        
        int find(int x){
            if(x == root[x])
                return x;
            root[x] = find(root[x]) ;
            return root[x] ;
        }
        
        void unionSet(int x, int y){
            int rootX = find(x) ;
            int rootY = find(y) ;
            
            if(rootX != rootY){
                if(rank[rootX] > rank[rootY]){
                    root[rootY] = rootX ;                    
                }
                else if(rank[rootX] < rank[rootY]){
                    root[rootY] = rootX ;
                }
                else{
                    root[rootY] = rootX ;
                    rank[rootX] += 1 ;
                }
            }
        }
        
        bool isConnected(int x, int y){
            return find(x) == find(y) ;
        }
        
        private:
        vector<int> root ;
        vector<int> rank ;
    } ;
    
    class edge{
        public:
        int u, v, w ;
        edge(int u, int v, int w): u(u), v(v), w(w){}
    } ;
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size() ;
        int dis, edgeCount = 0, u, v, w, minCost = 0;
        vector<vector<pair<int, int> >> graph(n) ;
        vector<edge> edges ;
        
        UnionFind ub(n) ;
        
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) ;
                edges.push_back(edge(i, j, dis)) ;
            }
        }
        
        sort(edges.begin(), edges.end(), [](edge &a, edge &b){
            return a.w < b.w ;
        });
        
        for(int i = 0 ; i < edges.size() ; i++){
            u = edges[i].u ;
            v = edges[i].v ;
            w = edges[i].w ;
            
            if(!ub.isConnected(u, v)){
                ub.unionSet(u, v) ;
                edgeCount++ ;
                minCost += w ;
                //cout<<u<<", "<<v<<", "<<w<<endl ;
            }
            
            if(edgeCount == n-1)
                break ;
        }
        
        /*
        for(auto e : edges){
            cout<<e.u<<", "<<e.v<<", "<<e.w<<endl ;
        }
        */
        
        return minCost ;
            
    }
};