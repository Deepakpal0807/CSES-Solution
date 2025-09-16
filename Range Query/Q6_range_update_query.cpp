#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> tree;
vector<ll> lazy;

void build(vector<ll>& v, ll i, ll j, ll ind) {
    if (i == j) {
        tree[ind] = v[i];
        return;
    }
    ll mid = (i + j) / 2;
    build(v, i, mid, ind * 2);
    build(v, mid + 1, j, ind * 2 + 1);
    tree[ind] = 0; // not important for point query
}

void lazyupdate(ll s, ll e, ll qs, ll qe, ll index, ll inc) {
    if (lazy[index] != 0) {
        tree[index] += lazy[index];
        if (s != e) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    if (e < qs || s > qe) return; // no overlap

    if (qs <= s && e <= qe) { // full overlap
        tree[index] += inc;
        if (s != e) {
            lazy[index * 2] += inc;
            lazy[index * 2 + 1] += inc;
        }
        return;
    }

    ll mid = (s + e) / 2;
    lazyupdate(s, mid, qs, qe, index * 2, inc);
    lazyupdate(mid + 1, e, qs, qe, index * 2 + 1, inc);
}

ll query(ll s, ll e, ll idx, ll ind) {
    if (lazy[ind] != 0) {
        tree[ind] += lazy[ind];
        if (s != e) {
            lazy[ind * 2] += lazy[ind];
            lazy[ind * 2 + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if (s == e) return tree[ind]; // reached the index

    ll mid = (s + e) / 2;
    if (idx <= mid) return query(s, mid, idx, ind * 2);
    else return query(mid + 1, e, idx, ind * 2 + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];

    tree.resize(4 * n + 1, 0);
    lazy.resize(4 * n + 1, 0);

    build(v, 0, n - 1, 1);

    for (ll i = 0; i < k; i++) {
        ll type;
        cin >> type;
        if (type == 1) { // update
            ll l, r, val;
            cin >> l >> r >> val;
            lazyupdate(0, n - 1, l - 1, r - 1, 1, val);
        } else { // query
            ll pos;
            cin >> pos;
            cout << query(0, n - 1, pos - 1, 1) << "\n";
        }
    }
}
