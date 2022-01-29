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

/*
class Edge {
public:
    int point1;
    int point2;
    int cost;
    Edge(int point1, int point2, int cost)
        : point1(point1), point2(point2), cost(cost) {}
};

// Overload the < operator.
bool operator<(const Edge& edge1, const Edge& edge2) {
    return edge1.cost > edge2.cost;
}

class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    // Kruskal's algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        int sz = points.size();
        priority_queue<Edge> pq;
        UnionFind uf(sz);

        for (int i = 0; i < sz; i++) {
            vector<int>& coordinate1 = points[i];
            for (int j = i + 1; j < sz; j++) {
                vector<int>& coordinate2 = points[j];
                // Calculate the distance between two coordinates.
                int cost = abs(coordinate1[0] - coordinate2[0]) +
                           abs(coordinate1[1] - coordinate2[1]);
                Edge edge(i, j, cost);
                pq.push(edge);
            }
        }

        int result = 0;
        int count = sz - 1;
        while (!pq.empty() && count > 0) {
            Edge edge = pq.top();
            pq.pop();
            if (!uf.connected(edge.point1, edge.point2)) {
                uf.unionSet(edge.point1, edge.point2);
                result += edge.cost;
                count--;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    Solution solution;
    cout << "Minimum Cost to Connect Points = " << solution.minCostConnectPoints(points) << endl;
    return 0;
}
*/