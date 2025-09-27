#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;

ll power(ll n) {
    if (n == 0) return 1;
    ll ans = power(n / 2);
    ans = (ans * ans) % MOD;
    if (n % 2) ans = (ans * 2) % MOD;
    return ans;
}

int main() {
    ll n;
    cin >> n;
    cout << power(n) << "\n";
}
