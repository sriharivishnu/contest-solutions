/*
    Solution by: Srihari Vishnu
    Created: January 20 2025

    2016OPENp1
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
const ll INF = 2e9;
const ld EPS = 1e-9;

const int MAXN = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<pii> pts(n);
    FOR(i, 0, n) { cin >> pts[i].fi >> pts[i].se; }

    sort(all(pts));
    set<pii> cands;
    FOR(i, 0, 4) cands.insert(pts[i]);
    FOR(i, 0, 4) cands.insert(pts[n - i - 1]);
    sort(all(pts), [](const auto& a, const auto& b) { return a.se < b.se; });
    FOR(i, 0, 4) cands.insert(pts[i]);
    FOR(i, 0, 4) cands.insert(pts[n - i - 1]);

    vector<pii> ok(all(cands));

    int ans = INF;
    FOR(i, 0, sz(ok)) {
        FOR(j, i + 1, sz(ok)) {
            FOR(k, j + 1, sz(ok)) {
                int mix = 40001, miy = 40001, mxx = -1, may = -1;
                FOR(l, 0, sz(ok)) {
                    if (l == i || l == j || l == k) continue;
                    mix = min(mix, ok[l].fi);
                    mxx = max(mxx, ok[l].fi);
                    miy = min(miy, ok[l].se);
                    may = max(may, ok[l].se);
                }

                ans = min((mxx - mix) * (may - miy), ans);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}