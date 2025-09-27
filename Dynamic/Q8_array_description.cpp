#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define fastio ios::sync_with_stdio(0); cin.tie(0)

// Shorthand
#define ll long long
#define vi vector<int>
#define endl '\n'

// Constants
const int MOD = 1e9+7;

int n, m;
vi arr;
vector<vi> dp;

ll solve(int i, int prev) {
    if(i == n) return 1;

    if(dp[i][prev] != -1) return dp[i][prev];

    ll ans = 0;
    if(arr[i] != 0) {
        if(prev == 0 || abs(arr[i] - prev) <= 1) {
            ans = solve(i+1, arr[i]);
        }
    } else {
        if(prev == 0) {
            for(int x=1; x<=m; x++) {
                ans += solve(i+1, x);
                if(ans >= MOD) ans -= MOD;
            }
        } else {
            for(int d=-1; d<=1; d++) {
                int x = prev + d;
                if(x>=1 && x<=m) {
                    ans += solve(i+1, x);
                    if(ans >= MOD) ans -= MOD;
                }
            }
        }
    }

    return dp[i][prev] = ans % MOD;
}

int main() {
    fastio;

    cin >> n >> m;
    arr.resize(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    dp.assign(n, vi(m+1, -1));

    cout << solve(0, 0) << endl;
}
