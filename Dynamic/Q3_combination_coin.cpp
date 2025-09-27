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

ll dp[1000001];

ll solve(ll n,vll& arr){
    if(n==0){
        return 1;
    }
    if(n<0)return 0;
    if(dp[n]!=-1){
        return dp[n];
    }

    ll ans=0;

    for(int i=0;i<(int)arr.size();i++){
          ans+=solve(n-arr[i],arr);
    }
    ans=ans%MOD;

    return dp[n]=ans;
}

int main() {
    fastio;
    memset(dp,-1,sizeof(dp));

    ll n,sum;
    cin>>n>>sum;

    vll arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    ll ans=solve(sum,arr);

    cout<<ans<<endl;
}
