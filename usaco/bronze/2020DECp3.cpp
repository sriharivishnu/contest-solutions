/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2020DECp3
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

const int MAXN = 2e5 + 5;

void solve() {
    int n;
    cin >> n;

    vector<char> dir(n);
    vector<int> x(n), y(n), ans(n, 2e9), pts(n);
    FOR(i, 0, n) cin >> dir[i] >> x[i] >> y[i];

    iota(all(pts), 0);
    sort(all(pts), [&](auto a, auto b) {
        if (dir[a] == dir[b]) {
            return dir[a] == 'E' ? y[a] < y[b] : x[a] < x[b];
        }
        return dir[a] < dir[b];
    });

    FOR(a, 0, n) {
        int i = pts[a];
        if (dir[i] == 'N') continue;
        FOR(b, 0, n) {
            int j = pts[b];
            if (dir[j] == 'E') continue;
            int t1 = 2e9, t2 = 2e9;
            if (y[i] >= y[j] && x[j] >= x[i]) t1 = x[j] - x[i];
            if (x[j] >= x[i] && y[i] >= y[j]) t2 = y[i] - y[j];
            if (t1 > t2 && t1 <= ans[j]) {
                ans[i] = min(ans[i], t1);
            } else if (t1 < t2 && t2 <= ans[i]) {
                ans[j] = min(ans[j], t2);
            }
        }
    }

    FOR(i, 0, n) {
        if (ans[i] == 2e9) {
            cout << "Infinity" << endl;
        } else {
            cout << ans[i] << endl;
        }
    }
}

int main() {
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}