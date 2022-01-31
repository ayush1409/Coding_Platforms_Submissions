class Solution {
public:
    
    // Prims algorithm without creating the complete graph
    class edge{
       public : 
        int u, v, dis ;
        edge(int u, int v, int dis) : u(u), v(v), dis(dis) {}
    } ;
    
    // overloading the operator
    //bool operator<(const edge &a, const edge &b){
    //    return a.w > b.w ;
    //}
    
    struct compareEdges{
        bool operator()(edge const& a, edge const& b){
            return a.dis > b.dis ;
        }
    };
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.size() <= 1)
            return 0 ;
        
        int n = points.size(), u, v, cost, dis, minCost = 0, vCount = 0;
        priority_queue<edge, vector<edge>, compareEdges> pq ;
        vector<bool> visited(n, false) ;
        
        for(int j = 1 ; j < n ; j++){
            dis = abs(points[0][0] - points[j][0]) + abs(points[0][1] - points[j][1]) ;
            pq.push(edge(0, j, dis)) ;
        }

        visited[0] = true ;
        
        while(!pq.empty()){
            edge curr = pq.top() ;
            pq.pop() ;
            
            u = curr.u ;
            v = curr.v ;
            cost = curr.dis ;
            
            if(!visited[v]){
                
                // include the edge in MST
                minCost += cost ;
                visited[v] = true ;
                
                // relax all the adjacent edges
                for(int j = 0 ; j < n ; j++){
                    dis = abs(points[j][0] - points[v][0]) + abs(points[j][1] - points[v][1]) ;
                    pq.push(edge(v, j, dis)) ;
                }
                
                vCount++ ;
            }
            
            // when n-1 vertex are being poped
            if(vCount == n-1)
                break ;
        }
        
        return minCost ;
        
    }

    // Using prims algorithm
    // This approach is taking lots of time as we are creating the complete graph the traversing it
    /*
    class node{
        public:
        int u, parent, key ;
        node(int u, int p, int k) : u(u), parent(p), key(k){}
    };
    
    struct compareNodes{
        bool operator()(node const& a, node const& b){
            return a.key > b.key ;
        }
    } ;
    
    class edge{
        public:
        int v, w ;
        edge(int v, int w): u(u), v(v), w(w){}
    } ;
    
    bool operator<(edge &a, edge &b){
        return a.w > b.w ;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), minCost = 0, dis ;
        //vector<int> key(n, INT_MAX) ;
        vector<bool> visited(n, false) ;
        //vector<vector<edge>> graph(n) ;
        
        // minHeap to store and retrieve the min keyvertex 
        priority_queue<node, vector<node>, compareNodes> q ;
        
        
        // construct the graph
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) ;
                graph[i].push_back(edge(j, dis)) ;
                graph[j].push_back(edge(i, dis)) ;
            }
        }
        
        q.push(node(0, -1, 0)) ;
        
        while(!q.empty()){
            node curr = q.top() ;
            q.pop() ;
            
            if(!visited[curr.u]){
                visited[curr.u] = true ;
                
                minCost += curr.key ;
                
                for(auto e : graph[curr.u]){
                    q.push(node(e.v, curr.u, e.w)) ;
                }
            }
        }
        
        return minCost ;
        
    }
    */
};