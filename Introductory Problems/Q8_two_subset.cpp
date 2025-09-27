#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0)

int main() {
    fastio;
    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    long long target = sum / 2;
    vector<int> set1, set2;

    for (int i = n; i >= 1; i--) {
        if (target >= i) {
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }

    // print first set
    cout << set1.size() << "\n";
    for (int x : set1) cout << x << " ";
    cout << "\n";

    // print second set
    cout << set2.size() << "\n";
    for (int x : set2) cout << x << " ";
    cout << "\n";
}
