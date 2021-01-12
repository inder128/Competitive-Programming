#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define ll long long
#define SZ(x) ((int)(x).size()) 
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#ifndef ONLINE_JUDGE 
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code Begins--------------------------------*/

const int N = 100;
vi adj[N], c(N);
set <pi> eqe;
vector <char> state(N, 'w');

void dfs(int node, int par = -1){
	state[node] = 'g';
	for(int child : adj[node]){
		if(c[node] != c[child]){
			continue;
		}
		if(child == par){
			continue;
		}
		if(state[child] != 'b'){
			eqe.insert({node, child});
		}
		if(state[child] == 'w'){
			dfs(child, node);
		}
	}
	state[node] = 'b';
}

void solve(){
    int n, m; cin >> n >> m;
    vector <pi> edges;
    for(int i = 0; i < m; ++i){
    	int u, v; cin >> u >> v;
    	u--, v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
    	edges.pb({u, v});
    }

    for(int i = 0; i < n; ++i){
    	cin >> c[i];
    }

    for(int i = 0; i < n; ++i){
    	if(state[i] == 'b'){
    		continue;
    	}
    	dfs(i);
    }

    for(pi eg : edges){
    	if(c[eg.F] > c[eg.S]){
    		cout << "->" << el;
    	}
    	else if(c[eg.F] < c[eg.S]){
    		cout << "<-" << el;
    	}
    	else{
    		if(eqe.count(eg)){
    			cout << "->" << el;
    		}
    		else{
    			cout << "<-" << el;
    		}
    	}
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}