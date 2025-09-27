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


int main() {
    fastio;

    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> brr(m);
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }

    vvi dp(n+1,vi(m+1,0));

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(arr[i]==brr[j]){
                dp[i][j]=dp[i+1][j+1]+1;
            }else{
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    cout<<dp[0][0]<<endl;
    int i=0;
    int j=0;
    while(i<n and j<m){
        if(arr[i]==brr[j]){
            cout<<arr[i]<<" ";
            i++;
            j++;
        }else{
            if(dp[i+1][j]>dp[i][j+1]){
                i++;
            }else{
                j++;
            }
        }
    }
    cout<<endl;
}
