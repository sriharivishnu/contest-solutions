/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2016FEBp3
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
    int n, q;
    cin >> n >> q;

    vector<pii> pts(n);
    set<int> xbs, ybs;

    FOR(i, 0, n) {
        cin >> pts[i].fi >> pts[i].se;
        xbs.insert(pts[i].fi + 1);
        ybs.insert(pts[i].se + 1);
    }

    int M = pts.size();
    for (auto xb : xbs) {
        for (auto yb : ybs) {
            int a = 0, b = 0, c = 0, d = 0;

            FOR(i, 0, n) {
                if (pts[i].fi < xb && pts[i].se < yb)
                    ++a;
                else if (pts[i].fi > xb && pts[i].se < yb)
                    ++b;
                else if (pts[i].fi < xb && pts[i].se > yb)
                    ++c;
                else
                    ++d;
            }
            M = min(M, max({a, b, c, d}));
        }
    }

    cout << M << endl;
}

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
