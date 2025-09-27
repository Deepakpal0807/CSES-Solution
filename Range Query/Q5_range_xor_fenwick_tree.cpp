#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define fastio ios::sync_with_stdio(0); cin.tie(0)

// Shorthand
#define ll long long
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define endl '\n'

// Loops
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(a); i>=(b); --i)
#define trav(a,x) for(auto &a : x)

// Constants
const ll INF = 1e18;
const int MOD = 1e9+7;

// Debug (only if needed)
#define dbg(x) cerr << #x << " = " << (x) << endl

// Typedefs for common 2D structures
using vvi = vector<vi>;
using vvll = vector<vll>;


vll tree;
void update(int i,ll val){
      while(i<(int)tree.size()){
        tree[i]^=val;
        i+=(i&(-i));
      }

      return ;
}

void bulidtree(vll& v){

    for(int i=0;i<(int)v.size();i++){
         update(i+1,v[i]);
    }
}

ll query(int i){
    ll ans=0;
    while(i>0){
        ans^=tree[i];
        i-=(i&(-i));
    }
    return ans;
}

int main() {
    fastio;
    ll n,k;
    cin>>n>>k;
    vll v(n);
    tree.resize(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    bulidtree(v);

    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        ll ans=query(b)^query(a-1);
        cout<<ans<<endl;
    }

}
