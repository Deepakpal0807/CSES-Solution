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

int dp[5001][5001];

int solve(string& a,string& b,int i,int j){
    //base condition ..
    if(i==a.size()){
        return b.size()-j;
    }
    if(j==b.size()){
        return a.size()-i;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    //add a char..
    int x=solve(a,b,i,j+1)+1;

    //remove a char..
    int y=solve(a,b,i+1,j)+1;

    //replace a char..
    int z=solve(a,b,i+1,j+1);
    if(a[i]!=b[j]){
        z++;  //if a[i]!=b[j] then one step there also but if it same then no step are there..
    }

    return dp[i][j]= min({x,y,z});
}

int main() {
    fastio;

    string a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));

    int ans=solve(a,b,0,0);
    cout<<ans<<endl;
}
