/*
    Solution by: Srihari Vishnu
    Created: January 02 2025

    2019p3
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#endif

#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define pb push_back
#define fi first
#define se second
#define mt make_tuple
#define FOR(i, L, R) for (int i = L; i < R; ++i)
#define RFOR(i, L, R) for (int i = L; i >= R; --i)
#define BTWN(i, l, r) ((l) <= (i) && (i) <= (r))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef tuple<int, int, int> tiii;

const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

const int MAXN = 2e5 + 3;

void solve() {
    int n;
    cin >> n;
    vector<string> op(n);
    vector<int> lows(n), highs(n);

    FOR(i, 0, n) cin >> op[i] >> lows[i] >> highs[i];

    int l = 0, r = 1e9;
    RFOR(i, n - 1, 0) {
        if (op[i] == "on") {
            l -= highs[i];
            r -= lows[i];
        } else if (op[i] == "off") {
            l += lows[i];
            r += highs[i];
        } else {
            l = max(l, lows[i]);
            r = min(r, highs[i]);
        }
        l = max(0, l);
    }
    cout << l << ' ' << r << endl;
    l = 0, r = 1e9;
    FOR(i, 0, n) {
        if (op[i] == "on") {
            l += lows[i];
            r += highs[i];
        } else if (op[i] == "off") {
            l -= highs[i];
            r -= lows[i];
        } else {
            l = max(l, lows[i]);
            r = min(r, highs[i]);
        }
        l = max(0, l);
    }
    cout << l << ' ' << r << endl;
}

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}