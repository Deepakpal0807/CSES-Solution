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

// int dp[1001][1001];
// int solve(vector<vector<char>>& arr,int i,int j){
//     if(i==arr.size() || j==arr.size()){
//         return 0;
//     }

//     if(arr[i][j]=='*')return 0;


//     if(i==arr.size()-1 and j==arr.size()-1)return 1;
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }

//     int ans=0;
//     ans+=solve(arr,i+1,j);
//     ans=ans%MOD;
//     ans+=solve(arr,i,j+1);
//     ans=ans%MOD;

//     return dp[i][j]=ans;
// }

int bottomup(vector<vector<char>>& arr){
     int size=arr.size();
    vvi dp(size+1,vi(size+1,0));
    if(arr[size-1][size-1]=='*' || arr[0][0]=='*'){
        return 0;
    }
    dp[size-1][size-1]=1;
    for(int i=size-1;i>=0;i--){
        for(int j=size-1;j>=0;j--){
            if(i==size-1 and j==size-1){
                continue;
            }
            if(arr[i][j]=='*'){
                continue;
            }
            dp[i][j]=dp[i+1][j]+dp[i][j+1];
            dp[i][j]%=MOD;
        }
    }
    return dp[0][0];

}

int main() {
    fastio;

    ll n;
    cin>>n;
    // memset(dp,-1,sizeof(dp));
    vector<vector<char>> arr(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    // ll ans=solve(arr,0,0);
    int ans=bottomup(arr);
    cout<<ans<<endl;
}
