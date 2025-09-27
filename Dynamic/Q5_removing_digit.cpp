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

int dp[1000001];

ll solve(ll n){
    // cout<<n<<endl;
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    string s=to_string(n);
    ll ans=INT_MAX;
    for(auto x:s){
        int ind=x-'0';
        if(ind!=0){
            ans=min(ans,solve(n-ind)+1);
        }
    }

    return dp[n]=ans;
}

int main() {
    fastio;
    memset(dp,-1,sizeof(dp));

    ll n;
    cin>>n;

    ll ans=solve(n);
    cout<<ans<<endl;
}
