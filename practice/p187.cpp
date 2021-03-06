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

const int N = 1e5;
set <int> adj[N];
vi ans;
vector <char> status(N, 'w');

bool eq(string str, string pat){
    int k = SZ(str);
    for(int i = 0; i < k; ++i){
        if(pat[i] == '_' or str[i] == pat[i]){
            continue;
        }
        return false;
    }
    return true;
}

bool dfs(int node){
    status[node] = 'g';
    for(int child : adj[node]){
        if(status[child] == 'b'){
            continue;
        }
        if(status[child] == 'g'){
            return false;
        }
        if(dfs(child) == false){
            return false;
        }
    }
    ans.pb(node);
    status[node] = 'b';
    return true;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector <string> pats(n), strs(m); cin >> pats;
    vi mt(m), in(n);

    map <string, int> patInd;
    for(int i = 0; i < n; ++i){
        patInd[pats[i]] = i;
    }

    for(int i = 0; i < m; ++i){
    	cin >> strs[i] >> mt[i];

    	for(int msk = 0; msk < (1 << k); ++msk){
    		string pat = strs[i];
    		for(int j = 0; j < k; ++j){
    			if(msk >> j & 1){
    				pat[j] = '_';
    			}
    		}
            if(pat != pats[mt[i] - 1] and patInd.find(pat) != patInd.end()){
                adj[mt[i] - 1].insert(patInd[pat]);
                in[patInd[pat]]++;
            }
    	}
    }

    for(int i = 0; i < m; ++i){
        if(eq(strs[i], pats[mt[i] - 1]) == false){
            cout << "No" << el;
            return;
        }
    }

    for(int i = 0; i < n; ++i){
        if(in[i] == 0 and status[i] == 'w'){
            if(dfs(i) == false){
                cout << "No" << el;
                return;
            }
        }
    }

    if(SZ(ans) != n){
        cout << "No" << el;
        return;
    }

    reverse(rng(ans));
    cout << "Yes" << el;
    for(int i : ans){
        cout << i + 1 << " ";
    }
    cout << el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}