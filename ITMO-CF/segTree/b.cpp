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
template<typename T>
istream&operator>>(istream&is,vector<T>&v){for(auto&it:v)is>>it;return is;}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.F << "," << P.S << ")"; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ "; for(auto v : V) os << v << " "; return os << "]"; }
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ "; for(auto s:S) os<<s<<" "; return os<<"}"; }
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout<<name<<" : "<<arg1<<'\n';}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names,comma-names)<<" : "<<arg1<<" |";__f(comma+1, args...);}
typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<vi> vvi;
 
/*-----------------------------Code begins----------------------------------*/

#define lsi 2*si + 1
#define rsi 2*si + 2
class segmentTree{
public :
	int size, n;
	int neutral = 0;
	vi ST;
	segmentTree(int _n){
		n = _n;
		size = 1;
		while(size < n) size <<= 1;
		ST.assign(2 * size, neutral);
	}


	inline int getMid(int &sl, int &sr){
		return (sl + sr) >> 1;
	}
	void printUtil(int si, int sl, int sr){
		cout<<si<<" : "<<sl<<" - "<<sr<<" : "<<ST[si]<<el;

		if(sl == sr) return;

		int mid = getMid(sl, sr);
		printUtil(lsi, sl, mid);
		printUtil(rsi, mid + 1, sr);
	}
	void print(){
		return printUtil(0, 0, n - 1);
	}


	void increaseUtil(int si, int sl, int sr, int i, int inc){
		if(sl == sr){
			ST[si] += inc;
			return;
		}

		int mid = getMid(sl, sr);
		if(i <= mid)
			increaseUtil(lsi, sl, mid, i, inc);
		else
			increaseUtil(rsi, mid + 1, sr, i, inc);

		ST[si] = ST[lsi] + ST[rsi];
	}
	void increase(int i, int inc){
		return increaseUtil(0, 0, n - 1, i, inc);
	}


	int getKthOneIndUtil(int si, int sl, int sr, int k){
		if(sl == sr) return sl;

		int mid = getMid(sl, sr);
		if(ST[lsi] >= k){
			return getKthOneIndUtil(lsi, sl, mid, k);
		}
		else{
			return getKthOneIndUtil(rsi, mid + 1, sr, k - ST[lsi]);
		}
	}
	int getKthOneInd(int k){
		return getKthOneIndUtil(0, 0, n - 1, k);
	}
};

void solve(){
    int n; cin>>n;
    segmentTree st(n + 1);
    for (int i = 1; i <= n; ++i){
    	st.increase(i, 1);
    }
    vi inv(n), ans(n); cin>>inv;
    for (int i = n - 1; i >= 0; --i){
    	int ai = st.getKthOneInd(i + 1 - inv[i]);
    	st.increase(ai, -1);
    	ans[i] = ai;
    }
    for(int i : ans) cout<<i<<" "; cout<<el;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}