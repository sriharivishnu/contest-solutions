/*
    Solution by: Srihari Vishnu
    Created: January 03 2025

    2020FEBp1
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
    vector<pii> pts(n);
    FOR(i, 0, n) cin >> pts[i].fi >> pts[i].se;
    sort(all(pts));
    int ans = 0;
    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            FOR(k, j + 1, n) {
                if (pts[i].fi == pts[j].fi &&
                    (pts[i].se == pts[k].se || pts[j].se == pts[k].se)) {
                    ans = max(
                        ans, (pts[j].se - pts[i].se) * (pts[k].fi - pts[i].fi));
                }

                if (pts[j].fi == pts[k].fi &&
                    (pts[i].se == pts[j].se || pts[i].se == pts[k].se)) {
                    ans = max(
                        ans, (pts[k].se - pts[j].se) * (pts[j].fi - pts[i].fi));
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}