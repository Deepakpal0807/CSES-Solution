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

int dp[1001][100001];

ll solve(vi& price,vi& page,int sum,int i){
     //base case..
    if(i==price.size()){
        return 0;
    }
    if(sum==0){
        return 0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }


    //take this book...

    ll a=0;
    if(sum>=price[i]){
    a=solve(price,page,sum-price[i],i+1)+page[i];
    }

   //leave this book
    ll b=solve(price,page,sum,i+1);


    return dp[i][sum]= max(a,b);
}
int main() {
    fastio;

    int n,sum;
    cin>>n>>sum;
    memset(dp,-1,sizeof(dp));

    vi price(n),page(n);

    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>page[i];
    }

    ll ans=solve(price,page,sum,0);
    cout<<ans<<endl;
}
