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



// vector<vector<int>> dp; // dp[sum][index]

// // recursive top-down with memoization
// ll solve(ll n, vi&arr, int i) {
//     if (n == 0) return 1;              // found valid combination
//     if (n < 0 || i == (int)arr.size()) return 0;  // invalid state

//     if (dp[n][i] != -1) return dp[n][i];

//     ll ans = 0;
//     // take current coin (stay at i, since unlimited usage allowed)
//     ans = (ans + solve(n - arr[i], arr, i)) % MOD;
//     // skip current coin (move to next index)
//     ans = (ans + solve(n, arr, i + 1)) % MOD;

//     return dp[n][i] = ans;
// }

int topdown(ll n,vi& arr){
    int size=arr.size();
    vvi dp(size+1,vi(n+1,0));

    for(int i=0;i<=size;i++){
        dp[i][0]=1;
    }

    for(int i=size-1;i>=0;i--){
        for(int j=1;j<=n;j++){
            if(arr[i]<=j){
                dp[i][j]+=dp[i][j-arr[i]];
            }
            dp[i][j]%=MOD;
            dp[i][j]+=dp[i+1][j];
            dp[i][j]%=MOD;
        }
    }

    return dp[0][n]%MOD;

}

int main() {
    fastio;
    ll n, sum;
    cin >> n >> sum;

    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(all(arr));

    // dp.assign(sum + 1, vector<int>(n + 1, -1));

    // cout << solve(sum, arr, 0) % MOD << "\n";
cout<<topdown(sum,arr)<<endl;
    return 0;
}
