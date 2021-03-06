#include <bits/stdc++.h>
using namespace std;
 
#define rng(x) x.begin(), x.end()
#define maxi(x, y) x = max(x, (y))
#define mini(x, y) x = min(x, (y))
#define pb push_back
#define F first
#define S second
#define el '\n'
#define int long long
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

int k;
vi fact(18 + 1);

map <pi, int> get(vi a){
	map <pi, int> ans;

	int n = SZ(a);
	for(int msk = 0; msk < (1 << n); ++msk){
		for(int subMsk = msk; ; subMsk = (subMsk - 1) & msk){
			if(__builtin_popcount(subMsk) > k){
				continue;
			}
			int csm = 0;
			for(int i = 0; i < n; ++i){
				if(subMsk >> i & 1){
					if(a[i] > 18){
						csm = -1;
						break;
					}
					csm += fact[a[i]];
				}
				else if(msk >> i & 1){
					csm += a[i];
				}
			}
			if(csm != -1){
				ans[{csm, __builtin_popcount(subMsk)}]++;
			}
			if(subMsk == 0){
				break;
			}
		}
	}

	return ans;
}


void solve(){
    fact[0] = 1;
    for(int i = 1; i <= 18; ++i){
    	fact[i] = i * fact[i - 1];
    }


    int n, s; cin >> n >> k >> s;
    vi a(n); cin >> a;

    if(n == 1){
    	int ans = 0;
    	ans += (s == a[0]);
    	if(a[0] <= 18 and fact[a[0]] == s){
    		ans++;
    	}
    	cout << ans << el;
    	return;
    }


    map <pi, int> vals1 = get(vi(a.begin(), a.begin() + n / 2));
    map <pi, int> vals2 = get(vi(a.begin() + n / 2, a.begin() + n));

    int ans = 0;
    for(auto [p, cnt] : vals1){
    	if(p.F > s){
    		break;
    	}
    	for(int i = 0; i <= k - p.S; ++i){
    		ans += cnt * vals2[{s - p.F, i}];
    	}
    }

    cout << ans << el;
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