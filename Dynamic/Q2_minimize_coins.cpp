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

ll solve(ll sum,vll& arr){
    if(sum==0){
        return 0;
    }
    if(sum<0){
        return 1e6;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }

    ll ans=INT_MAX;

    for(int i=0;i<arr.size();i++){
       ans=min(ans,solve(sum-arr[i],arr)+1);
    }

    return dp[sum]= ans;
}


int main() {
    fastio;

    ll n,sum;
    cin>>n>>sum;
    memset(dp,-1,sizeof(dp));

    vll arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(rall(arr));
    ll ans=solve(sum,arr);
    if(ans>1e6){
        cout<<-1<<endl;
    }else{
    cout<<ans<<endl;
}
}
