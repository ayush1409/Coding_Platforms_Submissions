#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

bool isSafeToPlace(vector<vector<bool>> &board, int row, int col){
	int n = board.size() ;
	vector<int> rowDir = {-1,-1,1,1,-2,-2,2,2} ;
	vector<int> colDir = {-2,2,-2,2,-1,1,-1,1} ;
	
	if(row < 0 || row > n-1 || col < 0 || col >= n-1)
		return false ;

	for(int i = 0 ; i < 8 ; i++){
		int x = row + rowDir[i] ;
		int y = col + colDir[i] ;
		if(x >= 0 && x <= n-1 && y >= 0 && y <= n-1)
			if(board[x][y])
				return false ;
	}
	return true ;
}

void printBoard(vector<vector<bool>> &board){
	int n = board.size() ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
			cout<<board[i][j]<<" " ;
		cout<<endl ;
	}
	cout<<endl ;
}

// kpsf = Knights placed so far
void nknights(vector<vector<bool>> &board, int i, int j, int n, int kpsf, string s){
	if(n == kpsf){
		//printf("%s\n", s);
		printBoard(board) ;
		return ;
	}

	if(j == n-1){
		i++ ;
		j = 0 ;
	}

	if(i == n){
		return ;
	}

	if(isSafeToPlace(board, i, j)){
		board[i][j] = true ;
		nknights(board, i, j+1, n, kpsf+1, s + "[" + to_string(i) + to_string(j) + "]") ;
		board[i][j] = false ;
	}

	nknights(board, i, j+1, n, kpsf, s) ;
}

void solve() {
    int n ;
    cin>>n ;
    vector<vector<bool>> board(n, vector<bool>(n, false)) ;

    nknights(board, 0, 0, n, 0, "") ;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  	base %= mod;
  	int result = 1;
  	while (exp > 0) {
    	if (exp & 1) result = ((ll)result * base) % mod;
    	base = ((ll)base * base) % mod;
    	exp >>= 1;
  	}
  	return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

