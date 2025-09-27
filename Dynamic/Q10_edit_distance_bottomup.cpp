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


int solve(string& a,string& b){
    int n=a.size();
    int m=b.size();
    vvll dp(n+1,vll(m+1,0));

    //base condition..
    for(int i=0;i<=n;i++){
        //if(j==b.size())
        //then this is the conditon..
        dp[i][m]=a.size()-i;
    }

    for(int j=0;j<=m;j++){
        //if(i==b.size())
        //then this is the conditon..
        dp[n][j]=b.size()-j;
    }
    

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            //add a char...
             int ins = 1 + dp[i][j + 1];
            // remove
            int rem = 1 + dp[i + 1][j];
            // replace or match
            int rep = dp[i + 1][j + 1] + (a[i] == b[j] ? 0 : 1);

            dp[i][j] = min({ins, rem, rep});       
         }
    }

    // for(auto x:dp){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    return dp[0][0];

}

int main() {
    fastio;

    string a,b;
    cin>>a>>b;
    // a="MOVIE";
    // b="LOVE";
    // memset(dp,-1,sizeof(dp));

    int ans=solve(a,b);
    cout<<ans<<endl;
}
